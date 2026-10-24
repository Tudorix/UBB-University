package Repository.db;

import Domain.Friendship;
import Domain.User;
import Repository.Repository;
import Validator.Validator;

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

    @Override
    public Friendship findOne(Integer ID){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Friendship save(Friendship entity){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Iterable<Friendship> findAll(){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Friendship delete(Integer id){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Friendship update(Friendship entity){
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
