package Exceptions;

public class ValidationException extends RuntimeException{
    public ValidationException(String message) {
        /**
         * Constructor for the ValidationException class
         *
         * @param message: the error message
         */
        super(message);
    }
}
