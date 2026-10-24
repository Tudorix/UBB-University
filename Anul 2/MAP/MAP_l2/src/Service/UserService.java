package Service;

import Domain.Friendship;
import Domain.User;
import Exceptions.DuplicateException;
import Exceptions.EntityNotFoundException;
import Repository.Repository;
import Repository.UserRepo;
import Validator.Validator;
import jdk.jfr.Frequency;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class UserService {
    Repository<Integer, User> userRepo;
    Repository<Integer, Friendship> friendshipRepo;

    public UserService(Repository<Integer, User> userRepo, Repository<Integer, Friendship> friendshipRepo) {
        /**
         * Constructor of UserService class
         *
         * @param userRepo: the repository of users
         */
        this.userRepo = userRepo;
        this.friendshipRepo = friendshipRepo;
    }
    public void addUser(String name, String email, int age, int id) {
        /**
         * Adds a user to the list of users
         *
         * @param name: the name of the user
         * @param email: the email of the user
         * @param age: the age of the user
         * @param id: the id of the user
         *
         * @throws DuplicateException if the user already exists
         */
        User user = new User(name, email, age, id);
        if(userRepo.findOne(id) != null) {
            throw new DuplicateException("User with id " + id + " already exists");
        }
        userRepo.save(user);
    }

    public Iterable<User> getAllUsers() {
        /**
         * Returns the list of users
         *
         * @return the list of users
         */
        return userRepo.findAll();
    }

    public boolean exists(String name) {
        /**
         * Checks if a user with the given name exists in the list of users
         *
         * @param name: the name of the user to be checked
         * @return true if the user exists, false otherwise
         */
        for(User user: userRepo.findAll()) {
            if(user.getName().equals(name)) {
                return true;
            }
        }
        return false;
    }

    public void removeUser(int id) {
        /**
         * Removes a user from the list of users
         *
         * @param id: the id of the user to be removed
         *
         * @throws EntityNotFoundException if the user with the given id does not exist
         */
        User user = userRepo.findOne(id);

        if (user == null) {
            throw new EntityNotFoundException("User with id " + id + " not found");
        }

        List<Integer> friendshipsToDelete = new ArrayList<>();

        for (Friendship f : friendshipRepo.findAll()) {
            if (f.getUser1().equals(user.getName()) || f.getUser2().equals(user.getName())) {
                friendshipsToDelete.add(f.getId());
            }
        }

        for (Integer friendshipId : friendshipsToDelete) {
            friendshipRepo.delete(friendshipId);
        }

        userRepo.delete(id);
    }
}
