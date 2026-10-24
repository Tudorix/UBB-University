package Repository.db;

import Domain.User;
import Repository.Repository;
import Validator.Validator;

public class UserDbRepository implements Repository<Integer, User> {
    private String url;
    private String username;
    private String password;
    private Validator<User> validator;

    public UserDbRepository(Validator<User> validator, String url, String username, String password) {
        this.validator = validator;
        this.url = url;
        this.username = username;
        this.password = password;
    }

    @Override
    public User findOne(Integer ID){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public User save(User entity){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Iterable<User> findAll(){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public User delete(Integer id){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public User update(User entity){
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
