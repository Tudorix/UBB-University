package Service;

import Domain.User;
import Exceptions.DuplicateException;
import Exceptions.EntityNotFoundException;
import Repository.UserRepo;
import Validator.Validator;

import java.util.ArrayList;

public class UserService {
    UserRepo userRepo;
    Validator<User> userValidator;

    public UserService(UserRepo userRepo, Validator<User> userValidator) {
        /**
         * Constructor of UserService class
         *
         * @param userRepo: the repository of users
         * @param userValidator: the validator of users
         */
        this.userRepo = userRepo;
        this.userValidator = userValidator;
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
        userValidator.validate(user);
        if(userRepo.exists(id)) {
            throw new DuplicateException("User with id " + id + " already exists");
        }
        userRepo.addUser(user);
    }

    public ArrayList<User> getAllUsers() {
        /**
         * Returns the list of users
         *
         * @return the list of users
         */
        return userRepo.getAllUsers();
    }

    public void removeUser(int id) {
        /**
         * Removes a user from the list of users
         *
         * @param id: the id of the user to be removed
         *
         * @throws EntityNotFoundException if the user with the given id does not exist
         */
        if(!userRepo.exists(id)) {
            throw new EntityNotFoundException("User with id " + id + " not found");
        }
        userRepo.removeUser(id);
    }
}
