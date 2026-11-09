package Exceptions;

public class EntityNotFoundException extends RuntimeException{
    public EntityNotFoundException(String message) {
        /**
         * Constructor for the EntityNotFoundException class
         *
         * @param message: the error message
         */
        super(message);
    }
}
