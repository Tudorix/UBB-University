package Repository.db;

import Domain.Friendship;
import Domain.User;
import Exceptions.RepositoryException;
import Repository.Repository;
import Validator.Validator;

import javax.xml.transform.Result;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class FriendshipDbRepository implements Repository<Integer, Friendship> {
    private String url;
    private String username;
    private String password;
    private Validator<Friendship> validator;

    public FriendshipDbRepository(Validator<Friendship> validator, String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    /**
     * Finds a friendship by its ID in the database.
     *
     * @param ID the ID of the friendship to find; must not be null
     * @return the friendship with the specified ID, or null if no such friendship exists
     * @throws IllegalArgumentException if the provided ID is null
     * @throws RepositoryException if there is an error during the find operation
     */
    @Override
    public Friendship findOne(Integer ID){
        if(ID == null){
            throw new IllegalArgumentException("ID cannot be null");
        }

        String sql = "SELECT * FROM public.friendships WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,ID);

            try(ResultSet result = statement.executeQuery()){
                if (result.next()) {
                    return new Friendship(
                            result.getInt("id"),
                            result.getString("user1"),
                            result.getString("user2"),
                            result.getTimestamp("friendship_date").toLocalDateTime()
                    );
                }
            }
        }catch (SQLException e){
            throw new RepositoryException("Error in finding friendship : " + e.getMessage(),e);
        }

        return null;
    }

    /**
     * Saves a friendship entity to the database.
     *
     * @param entity the friendship entity to be saved; must not be null
     * @return null if the friendship was successfully saved, or the provided entity if a friendship with the same ID already exists
     * @throws IllegalArgumentException if the provided entity is null
     * @throws RepositoryException if there is an error during the save operation
     */
    @Override
    public Friendship save(Friendship entity){
        if(entity == null){
            throw new IllegalArgumentException("Entity cannot be null");
        }

        validator.validate(entity);

        String sql = "INSERT INTO public.friendships (user1, user2, friendship_date) VALUES (?,?,?) returning id";

        try(Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setString(1,entity.getUser1());
            statement.setString(2,entity.getUser2());
            statement.setTimestamp(3,Timestamp.valueOf(entity.getDate()));

            try(ResultSet result = statement.executeQuery()){
                if (result.next()) {
                    entity.setId(result.getInt("id"));
                }
            }
        }catch (SQLException e){
            throw new RepositoryException("Error in saving friendship : " + e.getMessage(),e);
        }

        return null;
    }

    /**
     * Retrieves all friendships from the database.
     *
     * @return an iterable collection of all friendships
     * @throws RepositoryException if there is an error during the retrieval process
     */
    @Override
    public Iterable<Friendship> findAll(){
        List<Friendship> f = new ArrayList<>();
        String sql = "SELECT * FROM public.friendships";
        try(Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){

            try(ResultSet result = statement.executeQuery()){
                while (result.next()) {
                    f.add(new Friendship(
                            result.getInt("id"),
                            result.getString("user1"),
                            result.getString("user2"),
                            result.getTimestamp("friendship_date").toLocalDateTime()
                    ));
                }
            }
        }catch (SQLException e){
            throw new RepositoryException("Error in finding friendship : " + e.getMessage(),e);
        }

        return f;
    }

    /**
     * Deletes a friendship from the database based on the provided ID.
     *
     * @param id the unique identifier of the friendship to be deleted; must not be null
     * @return the deleted friendship if it was found and removed, or null if no friendship with the provided ID exists
     * @throws IllegalArgumentException if the provided ID is null
     * @throws RepositoryException if there is an error during the deletion process
     */
    @Override
    public Friendship delete(Integer id){
        if(id == null){
            throw new IllegalArgumentException("ID cannot be null");
        }

        Friendship f = findOne(id);
        if(f == null){
            return null;
        }

        String sql = "DELETE FROM public.friendships WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setInt(1,id);
            statement.executeUpdate();
        }catch (SQLException e){
            throw new RepositoryException("Error in deleting friendship : " + e.getMessage(),e);
        }

        return f;
    }

    /**
     * Updates an existing friendship in the database.
     *
     * @param entity the friendship entity to be updated; must not be null
     * @return null if the update was successful, or the provided entity if no friendship with the same ID exists
     * @throws IllegalArgumentException if the provided entity is null
     * @throws RepositoryException if there is an error during the update process
     */
    @Override
    public Friendship update(Friendship entity){
        if(entity == null){
            throw new IllegalArgumentException("Entity cannot be null");
        }

        validator.validate(entity);

        String sql = "UPDATE public.friendships SET user1 = ? , user2 = ?, friendship_date = ? WHERE id = ?";

        try(Connection connection = DriverManager.getConnection(url,username,password);
            PreparedStatement statement = connection.prepareStatement(sql)){
            statement.setString(1,entity.getUser1());
            statement.setString(2,entity.getUser2());
            statement.setTimestamp(3,Timestamp.valueOf(entity.getDate()));
            statement.setInt(4,entity.getId());
            int rowsAffected = statement.executeUpdate();

            if (rowsAffected == 0)
                return entity;
        }catch (SQLException e){
            throw new RepositoryException("Error in updating friendship : " + e.getMessage(),e);
        }

        return null;
    }

}
