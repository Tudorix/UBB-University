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

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;
import java.util.function.Supplier;

public class RepositoryFactory {
    private Properties properties;

    public RepositoryFactory() {
        properties = new Properties();
        try (InputStream input = new FileInputStream("config.properties")) {

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
        Map<RepositoryType, Supplier<Repository<Integer, User>>> factories = new HashMap<>();
        factories.put(RepositoryType.MEMORY, () -> new InMemoryRepository(validator));
        factories.put(RepositoryType.FILE, () -> new UserFileRepository(validator,getRequiredProperty("user.filename")));
        factories.put(RepositoryType.DATABASE, () -> new UserDbRepository(validator, getRequiredProperty("user.database.url"), getRequiredProperty("user.database.username"), getRequiredProperty("user.database.password")));

        String ptype = getRequiredProperty("repository.type");
        RepositoryType type = RepositoryType.valueOf(ptype.trim().toUpperCase());

        Supplier<Repository<Integer, User>> supplier = factories.get(type);

        if (supplier == null) {
            throw new IllegalArgumentException("Invalid repository type!");
        }

        return supplier.get();
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
        Map<RepositoryType, Supplier<Repository<Integer,Friendship>>> factory = new HashMap<>();
        factory.put(RepositoryType.MEMORY, () -> new InMemoryRepository<Integer, Friendship>(validator));
        factory.put(RepositoryType.FILE, () -> new FriendshipFileRepository(validator,getRequiredProperty("friendship.filename"),userRepo));
        factory.put(RepositoryType.DATABASE, () -> new FriendshipDbRepository(validator, getRequiredProperty("friendship.database.url"), getRequiredProperty("friendship.database.username"), getRequiredProperty("friendship.database.password")));

        String ptype = getRequiredProperty("repository.type");
        RepositoryType type = RepositoryType.valueOf(ptype.trim().toUpperCase());

        Supplier<Repository<Integer,Friendship>> supplier = factory.get(type);

        if(supplier == null){
            throw new IllegalArgumentException("INvalid repository type");
        }

        return  supplier.get();
    }
}
