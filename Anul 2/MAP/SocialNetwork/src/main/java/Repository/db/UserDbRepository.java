package Repository.db;

import Domain.Friendship;
import Domain.User;
import Exceptions.RepositoryException;
import Repository.Repository;
import Validator.Validator;

import java.sql.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.function.Predicate;

public class UserDbRepository implements Repository<Integer, User> {
    private final String url;
    private final String username;
    private final String password;
    private final Validator<User> validator;

    public UserDbRepository(Validator<User> validator, String url, String username, String password) {
        this.validator = validator;
        this.url = url;
        this.username = username;
        this.password = password;
    }

    /**
     * Finds a user by their ID in the database.
     * @param ID the ID of the user to find; must not be null.
     * @return the user with the specified ID, or null if no such user exists.
     * @throws IllegalArgumentException if the provided ID is null.
     * @throws RepositoryException if there is an error during the find operation.
     */
    @Override
    public User findOne(Integer ID){
        if (ID == null)
            throw new IllegalArgumentException("ID cannot be null");

        String sql = "SELECT * FROM public.users WHERE ID = ?";

        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, ID);

            try (ResultSet result = statement.executeQuery()) {
                if (result.next()) {
                    return new User(
                            result.getString("name"),
                            result.getString("email"),
                            result.getInt("age"),
                            result.getInt("id")
                    );
                }
            }

        } catch (SQLException e) {
            throw new RepositoryException("Error finding user: " + e.getMessage(), e);
        }

        return null;
    }

    /**
     * Saves a user entity to the database.
     * @param entity the user entity to be saved; must not be null.
     * @return null if the user was successfully saved, or the provided entity if a user with the same ID already exists.
     * @throws IllegalArgumentException if the provided entity is null.
     * @throws RepositoryException if there is an error during the save operation.
     */
    @Override
    public User save(User entity){
        if (entity == null)
            throw new IllegalArgumentException("User cannot be null");

        validator.validate(entity);

        String sql = "INSERT INTO public.users (name,email,age) VALUES(?,?,?) RETURNING id";

        try (Connection connection = DriverManager.getConnection(url,username,password);
          PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setString(1,entity.getName());
            statement.setString(2,entity.getEmail());
            statement.setInt(3,entity.getAge());

            try (ResultSet result = statement.executeQuery()) {
                if (result.next()) {
                    entity.setId(result.getInt("id"));
                }
            }
        }catch (SQLException e){
            throw new RepositoryException("Error in saving user: " + e.getMessage(),e);
        }

        return null;
    }

    /**
     * Retrieves all users from the database.
     *
     * @return an iterable collection of all users
     * @throws RepositoryException if there is an error during the retrieval process
     */
    @Override
    public Iterable<User> findAll(){
        String sql = "SELECT * FROM public.users";

        List<User> users = new ArrayList<>();

        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement(sql)) {

            try (ResultSet result = statement.executeQuery()) {
                while (result.next()) {
                    User u = new User(
                            result.getString("name"),
                            result.getString("email"),
                            result.getInt("age"),
                            result.getInt("id")
                    );

                    users.add(u);
                }
            }

        } catch (SQLException e) {
            throw new RepositoryException("Error retrieving users: " + e.getMessage(), e);
        }

        return users;
    }

    /**
     * Deletes a user from the database based on the provided ID.
     * @param id id must be not null
     * @return null if the user was successfully deleted, or the deleted user if it was found and removed.
     * @return the deleted user if it was found and removed, or null if no user with the provided ID exists.
     * @throws RepositoryException if there is an error during the deletion process.
     * @throws IllegalArgumentException if the provided ID is null.
     */
    @Override
    public User delete(Integer id){
        if(id == null){
            throw new IllegalArgumentException("ID cannot be null");
        }

        User u = findOne(id);

        if(u == null){
            return null;
        }

        String sql = "DELETE FROM public.users WHERE id = ?";

        try (Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){

            statement.setInt(1,id);
            statement.executeUpdate();
        }catch (SQLException e){
            throw new RepositoryException("Error in delete : " + e.getMessage(),e);
        }

        return u;
    }

    /**
     * Updates an existing user in the database.
     * @param entity the user entity to be updated; must not be null.
     * @return null if the update was successful, or the provided entity if no user with the same ID exists.
     * @throws IllegalArgumentException if the provided entity is null.
     * @throws RepositoryException if there is an error during the update process.
     */
    @Override
    public User update(User entity){
        if (entity == null)
            throw new IllegalArgumentException("User cannot be null");

        validator.validate(entity);
        int id = entity.getId();

        String sql = "UPDATE public.users SET name = ?, email = ? ,age = ? WHERE id = ?";

        try(Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setString(1,entity.getName());
            statement.setString(2,entity.getEmail());
            statement.setInt(3,entity.getAge());
            statement.setInt(4,id);

            int rowsAffected = statement.executeUpdate();

            if (rowsAffected == 0)
                return entity;
        }catch (SQLException e){
            throw new RepositoryException("Error updating user: " + e.getMessage(), e);
        }
        return null;
    }

}
