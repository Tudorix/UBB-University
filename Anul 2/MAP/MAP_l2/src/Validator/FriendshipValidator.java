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
        if(entity.getId() < 0) {
            throw new ValidationException("Friendship id cannot be negative");
        }

        if(entity.getUser1Id() < 0) {
            throw new ValidationException("User1 id cannot be negative");
        }

        if(entity.getUser2Id() < 0) {
            throw new ValidationException("User2 id cannot be negative");
        }
    }
}
