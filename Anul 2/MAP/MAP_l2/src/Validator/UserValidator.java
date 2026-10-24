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
        String errors = "";

        if (entity.getName() == null || entity.getName().isBlank()) {
            errors += "User name cannot be empty\n";
        }

        if (entity.getEmail() == null || entity.getEmail().isBlank()) {
            errors += "User email cannot be empty\n";
        } else if (!entity.getEmail().matches("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$")) {
            errors += "User email is invalid\n";
        }

        if (entity.getAge() < 0) {
            errors += "User age cannot be negative\n";
        }

        if (entity.getId() == null || entity.getId() < 0) {
            errors += "User ID cannot be null or negative\n";
        }

        if (!errors.isEmpty()) {
            throw new ValidationException(errors);
        }
    }
}
