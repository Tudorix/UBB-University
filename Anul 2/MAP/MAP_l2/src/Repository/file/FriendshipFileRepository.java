package Repository.file;

import Domain.Friendship;
import Domain.User;
import Exceptions.ValidationException;
import Repository.Repository;
import Validator.Validator;

import java.time.LocalDateTime;
import java.util.Date;

public class FriendshipFileRepository extends AbstractFileRepository<Integer, Friendship> {

    private Repository<Integer, User> userRepo;

    public FriendshipFileRepository(Validator<Friendship> validator, String filename, Repository<Integer,User> userRepo) {
        super(validator, filename);
        this.userRepo = userRepo;
        super.loadData();
    }

    private boolean userExists(String username) {
        for (User user : userRepo.findAll()) {
            if (user.getName().equals(username)) {
                return true;
            }
        }
        return false;
    }


    /**
     * Converts a line from the file into a Friendship object.
     *
     * @param line the line containing the user's data
     * @return the Friendship object created from the line
     * @throws IllegalArgumentException if the line contains invalid data
     */
    @Override
    protected Friendship extractEntity(String line) {
        String[] fields = line.split(";", -1);
        if (fields.length != 4) {
            throw new IllegalArgumentException(
                    "Expected 4 fields, found " + fields.length
            );
        }
        Friendship f = new Friendship(Integer.parseInt(fields[0]), fields[1], fields[2], LocalDateTime.parse(fields[3]));
        if(!userExists(f.getUser1()) || !userExists(f.getUser2())){
            throw new ValidationException("User does not exist");
        }
        return f;
    }

    /**
     * Converts a Friendship object into a semicolon-separated string.
     *
     * @param entity the Friendship object to convert
     * @return the string representation of the friendship
     */
    @Override
    protected String createEntityAsString(Friendship entity) {
        return entity.getId() + ";" +
                entity.getUser1() + ";" +
                entity.getUser2() + ";" +
                entity.getDate();
    }

}
