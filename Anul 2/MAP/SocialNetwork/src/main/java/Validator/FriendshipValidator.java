package Validator;

import Domain.Friendship;
import Exceptions.ValidationException;

public class FriendshipValidator implements Validator<Friendship> {
    @Override
    public void validate(Friendship entity) {
        /**
         * Validates a Friendship entity
         *
         * @param entity: the Friendship entity to be validated
         * @throws ValidationException if the Friendship entity is not valid
         */

        String errors = "";
        if(entity.getId() < 0) {
            errors += "Friendship id cannot be negative";
        }

        if(entity.getUser2() == null || entity.getUser2().isEmpty()) {
            errors += "User2 cannot be null or empty";
        }

        if(entity.getUser1() == null || entity.getUser1().isEmpty()) {
            errors += "User1 cannot be null or empty";
        }

        if (!errors.isEmpty()) {
            throw new ValidationException(errors);
        }
    }
}
