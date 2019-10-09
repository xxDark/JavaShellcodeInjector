package one.helfy;

public final class JVMException extends RuntimeException {

    public JVMException(String message) {
        super(message);
    }

    public JVMException(String message, Throwable cause) {
        super(message, cause);
    }

    public JVMException(Throwable cause) {
        super(cause);
    }
}
