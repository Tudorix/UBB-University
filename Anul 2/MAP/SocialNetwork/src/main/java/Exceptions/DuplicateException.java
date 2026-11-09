package Exceptions;

public class DuplicateException extends RuntimeException{
    public DuplicateException(String message) {
        /**
         * Constructor for the DuplicateException class
         *
         * @param message: the error message
         */
        super(message);
    }
}
