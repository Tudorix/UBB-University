package Validator;

import Domain.User;
import Exceptions.ValidationException;

public class UserValidator implements Validator<User> {
    @Override
    public void validate(User entity) {
        /**
         * Validates a User entity
         *
         * @param entity: the User entity to be validated
         * @throws ValidationException if the User entity is not valid
         */
        if(entity.getName() == null || entity.getName().isEmpty()) {
            throw new ValidationException("User name cannot be null or empty");
        }

        if(entity.getEmail() == null || entity.getEmail().isEmpty()) {
            throw new ValidationException("User email cannot be null or empty");
        }

        if(!entity.getEmail().matches("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$")) {
            throw new ValidationException("User email is not valid");
        }

        if(entity.getAge() < 0) {
            throw new ValidationException("User age cannot be negative");
        }

        if(entity.getId() < 0) {
            throw new ValidationException("User id cannot be negative");
        }
    }
}
