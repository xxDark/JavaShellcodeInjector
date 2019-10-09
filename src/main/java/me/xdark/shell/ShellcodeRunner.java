package me.xdark.shell;

import one.helfy.JVM;
import one.helfy.Type;
import sun.misc.Unsafe;

import java.nio.charset.StandardCharsets;

public final class ShellcodeRunner {

    private static final JVM jvm = new JVM();

    private ShellcodeRunner() {
    }

    public static void inject(Class<?> target, String name, String descriptor, byte[] payload) {
        // Before execution: prepare the method to match the exact size of payload you want to execute
        // execute it ~~20000 times let JIT do it's work
        // After injection call the method again
        Unsafe unsafe = JVMUtil.UNSAFE;
        JVM jvm = ShellcodeRunner.jvm;
        int oopSize = jvm.intConstant("oopSize");
        long klassOffset = jvm.getInt(jvm.type("java_lang_Class").global("_klass_offset"));
        long klass = oopSize == 8
                ? unsafe.getLong(target, klassOffset)
                : unsafe.getInt(target, klassOffset) & 0xffffffffL;

        long methodArray = jvm.getAddress(klass + jvm.type("InstanceKlass").offset("_methods"));
        int methodCount = jvm.getInt(methodArray);
        long methods = methodArray + jvm.type("Array<Method*>").offset("_data");

        long constMethodOffset = jvm.type("Method").offset("_constMethod");
        Type constMethodType = jvm.type("ConstMethod");
        Type constantPoolType = jvm.type("ConstantPool");
        long constantPoolOffset = constMethodType.offset("_constants");
        long nameIndexOffset = constMethodType.offset("_name_index");
        long signatureIndexOffset = constMethodType.offset("_signature_index");
        long _from_compiled_entry = jvm.type("Method").offset("_from_compiled_entry");

        for (int i = 0; i < methodCount; i++) {
            long method = jvm.getAddress(methods + i * oopSize);
            long constMethod = jvm.getAddress(method + constMethodOffset);

            long constantPool = jvm.getAddress(constMethod + constantPoolOffset);
            int nameIndex = jvm.getShort(constMethod + nameIndexOffset) & 0xffff;
            int signatureIndex = jvm.getShort(constMethod + signatureIndexOffset) & 0xffff;

            if (name.equals(getSymbol(constantPool + constantPoolType.size + nameIndex * oopSize))
                    && descriptor.equals(getSymbol(
                    constantPool + constantPoolType.size + signatureIndex * oopSize))) {
                long address = jvm.getAddress(method + _from_compiled_entry);
                // let's rock!
                for (int j = 0, k = payload.length; j < k; j++) {
                    unsafe.putByte(address+j, payload[j]);
                }
                return;
            }
        }
        throw new InternalError(target + "." + name + descriptor);
    }

    private static String getSymbol(long symbolAddress) {
        Type symbolType = jvm.type("Symbol");
        long symbol = jvm.getAddress(symbolAddress);
        long body = symbol + symbolType.offset("_body");
        int length = jvm.getShort(symbol + symbolType.offset("_length")) & 0xffff;

        byte[] b = new byte[length];
        for (int i = 0; i < length; i++) {
            b[i] = jvm.getByte(body + i);
        }
        return new String(b, StandardCharsets.UTF_8);
    }
}
