package Service;

import Domain.Friendship;
import Domain.User;
import Exceptions.DuplicateException;
import Exceptions.EntityNotFoundException;
import Repository.Repository;
import jdk.jfr.Frequency;

import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

import java.util.ArrayList;
import java.util.List;

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
        return StreamSupport.stream(userRepo.findAll().spliterator(), false).anyMatch((User u) -> u.getName().equals(name));
    }

    public List<String> getFriends(int id){
        User u = Optional.ofNullable(userRepo.findOne(id)).orElseThrow(() -> {
            return new IllegalArgumentException("User not found");
        });

        String uname = u.getName();

        List<String> friends = StreamSupport.stream(friendshipRepo.findAll(f -> f.getUser1().equals(uname) || f.getUser2().equals(uname)).spliterator(),false).map(f ->{
            if(f.getUser2().equals(uname)) return f.getUser1();
            return f.getUser2();
        }).toList();
        return friends;
    }

    public void removeUser(int id) {
        /**
         * Removes a user from the list of users
         *
         * @param id: the id of the user to be removed
         *
         * @throws EntityNotFoundException if the user with the given id does not exist
         */
        User user = Optional.ofNullable(userRepo.findOne(id)).orElseThrow(() -> {
           return new EntityNotFoundException("User with id " + id + " not found");
        });

        List<Integer> friendshipsToDelete = StreamSupport.stream(friendshipRepo.findAll().spliterator(), false)
                .filter((Friendship f) -> f.getUser1().equals(user.getName()) || f.getUser2().equals(user.getName()))
                .map(Friendship::getId).collect(Collectors.toList());

        friendshipsToDelete.forEach(friendshipRepo::delete);

        userRepo.delete(id);
    }
}
