package me.xdark.shell;

import sun.misc.Unsafe;

import java.lang.invoke.MethodHandle;
import java.lang.invoke.MethodHandles;
import java.lang.invoke.MethodType;
import java.lang.reflect.Field;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;

public final class JVMUtil {

    public static final Unsafe UNSAFE;
    public static final MethodHandles.Lookup LOOKUP;
    private static final NativeLibraryLoader NATIVE_LIBRARY_LOADER;

    private JVMUtil() {
    }

    public static NativeLibrary findJvm() throws Throwable {
        Path jvmDir = Paths.get(System.getProperty("java.home"));
        Path maybeJre = jvmDir.resolve("jre");
        if (Files.isDirectory(maybeJre)) {
            jvmDir = jvmDir.resolve(maybeJre);
        }
        jvmDir = jvmDir.resolve("bin");
        String os = System.getProperty("os.name").toLowerCase();
        Path pathToJvm;
        if (os.contains("win")) {
            pathToJvm = findFirstFile(jvmDir, "server/jvm.dll", "client/jvm.dll");
        } else if (os.contains("nix") || os.contains("nux")) {
            pathToJvm = findFirstFile(jvmDir, "lib/amd64/server/libjvm.so", "lib/i386/server/libjvm.so");
        } else {
            throw new RuntimeException("Unsupported OS (probably MacOS X): " + os);
        }
        return NATIVE_LIBRARY_LOADER.loadLibrary(pathToJvm.normalize().toString());
    }

    private static Path findFirstFile(Path directory, String... files) {
        for (String file : files) {
            Path path = directory.resolve(file);
            if (Files.exists(path)) return path;
        }
        throw new RuntimeException("Failed to find one of the required paths!: " + Arrays.toString(files));
    }

    static {
        try {
            Field field = Unsafe.class.getDeclaredField("theUnsafe");
            field.setAccessible(true);
            Unsafe unsafe = UNSAFE = (Unsafe) field.get(null);
            MethodHandles.publicLookup();
            field = MethodHandles.Lookup.class.getDeclaredField("IMPL_LOOKUP");
            LOOKUP = (MethodHandles.Lookup) unsafe.getObject(unsafe.staticFieldBase(field),
                    unsafe.staticFieldOffset(field));
            NATIVE_LIBRARY_LOADER = Float.parseFloat(System.getProperty("java.class.version")) - 44 > 8 ? null : new Java8LibraryLoader();
        } catch (Throwable t) {
            throw new ExceptionInInitializerError(t);
        }
    }

    private static abstract class NativeLibraryLoader {

        protected static final Class<?> CL_NATIVE_LIBRARY;
        protected static final MethodHandle CNSTR_NATIVE_LIBRARY;

        abstract NativeLibrary loadLibrary(String path) throws Throwable;

        static {
            try {
                CL_NATIVE_LIBRARY = Class.forName("java.lang.ClassLoader$NativeLibrary", true, null);
                CNSTR_NATIVE_LIBRARY = LOOKUP.findConstructor(Class.forName("java.lang.ClassLoader$NativeLibrary"), MethodType.methodType(Void.TYPE, Class.class, String.class, Boolean.TYPE));
            } catch (Throwable t) {
                throw new ExceptionInInitializerError(t);
            }
        }
    }

    private static class Java8LibraryLoader extends NativeLibraryLoader {

        private static final MethodHandle MH_NATIVE_LOAD;
        private static final MethodHandle MH_NATIVE_FIND;
        private static final MethodHandle MH_NATIVE_LOADED_SET;

        @Override
        NativeLibrary loadLibrary(String path) throws Throwable {
            Object library = CNSTR_NATIVE_LIBRARY.invoke(JVMUtil.class, path, false);
            MH_NATIVE_LOAD.invoke(library, path, false);
            MH_NATIVE_LOADED_SET.invoke(library, true);
            return new NativeLibrary() {
                @Override
                public long findEntry(String entry) {
                    try {
                        return (long) MH_NATIVE_FIND.invoke(library, entry);
                    } catch (Throwable t) {
                        throw new InternalError(t);
                    }
                }
            };
        }

        static {
            MethodHandles.Lookup lookup = LOOKUP;
            Class<?> cl = CL_NATIVE_LIBRARY;
            try {
                MH_NATIVE_LOAD = lookup.findVirtual(cl, "load", MethodType.methodType(Void.TYPE, String.class, Boolean.TYPE));
                MH_NATIVE_FIND = lookup.findVirtual(cl, "find", MethodType.methodType(Long.TYPE, String.class));
                MH_NATIVE_LOADED_SET = lookup.findSetter(cl, "loaded", Boolean.TYPE);
            } catch (Throwable t) {
                throw new ExceptionInInitializerError(t);
            }

        }
    }
}
