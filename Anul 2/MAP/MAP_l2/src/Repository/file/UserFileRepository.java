package Repository.file;

import Domain.User;
import Validator.Validator;

public class UserFileRepository extends AbstractFileRepository<Integer, User>{

    public UserFileRepository(Validator<User> validator,String filename){
        super(validator,filename);
        super.loadData();
    }

    /**
     * Converts a line from the file into a User object.
     *
     * @param line the line containing the user's data
     * @return the User object created from the line
     * @throws IllegalArgumentException if the line contains invalid data
     */
    @Override
    protected User extractEntity(String line){
        String[] fields = line.split(";",-1);
        if (fields.length != 4) {
            throw new IllegalArgumentException(
                    "Expected 4 fields, found " + fields.length
            );
        }
        User u = new User(fields[1],fields[2],Integer.parseInt(fields[3]),Integer.parseInt(fields[0]));
        return u;
    }

    /**
     * Converts a User object into a semicolon-separated string.
     *
     * @param entity the User object to convert
     * @return the string representation of the user
     */
    @Override
    protected String createEntityAsString(User entity){
        return entity.getId() + ";" + entity.getName() + ";" + entity.getEmail() + ";" + entity.getAge();
    }
}
