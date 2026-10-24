package Repository.factory;

import Domain.Friendship;
import Domain.User;
import Exceptions.RepositoryException;
import Repository.InMemoryRepository;
import Repository.Repository;
import Repository.db.FriendshipDbRepository;
import Repository.db.UserDbRepository;
import Repository.file.FriendshipFileRepository;
import Repository.file.UserFileRepository;
import Validator.Validator;

import javax.print.DocFlavor;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class RepositoryFactory {
    private Properties properties;

    public RepositoryFactory() {
        properties = new Properties();
        try (InputStream input = new FileInputStream("src/resources/config.properties")) {

            if (input == null)
                throw new IllegalStateException("Config file not found!");

            properties.load(input);

        } catch (IOException e) {
            throw new RepositoryException("Error reading config", e);
        }
    }

    private String getRequiredProperty(String key) {
        String value = properties.getProperty(key);

        if (value == null || value.isBlank()) {
            throw new IllegalArgumentException(
                    "Missing property: " + key
            );
        }

        return value;
    }

    /**
     * Creates a user repository based on the configured persistence type.
     *
     * @param validator the validator for user entities
     * @return the configured user repository
     * @throws IllegalArgumentException if the repository type is invalid
     */
    public Repository<Integer, User> createUserRepository(Validator<User> validator) {
        String ptype = getRequiredProperty("repository.type");
        RepositoryType type = RepositoryType.valueOf(ptype.trim().toUpperCase());
        switch (type) {
            case MEMORY:
                return new InMemoryRepository(validator);
            case FILE:
                return new UserFileRepository(validator,getRequiredProperty("user.filename"));
            case DATABASE:
                return new UserDbRepository(validator, getRequiredProperty("user.database.url"), getRequiredProperty("user.database.username"), getRequiredProperty("user.database.password"));
            default:
                throw new IllegalArgumentException("Invalid repository type");
        }
    }

    /**
     * Creates a friendship repository based on the configured persistence type.
     *
     * @param validator the validator for friendship entities
     * @param userRepo the user repository used to validate friendship references
     * @return the configured friendship repository
     * @throws IllegalArgumentException if the repository type is invalid
     */
    public Repository<Integer, Friendship> createFriendshipRepository(Validator<Friendship> validator, Repository<Integer, User> userRepo) {
        String ptype = getRequiredProperty("repository.type");
        RepositoryType type = RepositoryType.valueOf(ptype.trim().toUpperCase());
        switch (type) {
            case MEMORY:
                return new InMemoryRepository(validator);
            case FILE:
                return new FriendshipFileRepository(validator,getRequiredProperty("friendship.filename"),userRepo);
            case DATABASE:
                return new FriendshipDbRepository(validator, getRequiredProperty("friendship.database.url"), getRequiredProperty("friendship.database.username"), getRequiredProperty("friendship.database.password"));
            default:
                throw new IllegalArgumentException("Invalid repository type");
        }
    }
}
