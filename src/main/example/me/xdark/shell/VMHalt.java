package me.xdark.shell;

public class VMHalt {
    private static int x1;

    public static void main(String[] args) {
        int i = 20000;
        while (i-- > 0) test();
        ShellcodeRunner.inject(VMHalt.class, "test", "()V", new byte[]{(byte) 0x90, (byte) 0xeb, (byte) 0xfd});
        test();
    }

    public static void test() {
        x1++;
    }
}
