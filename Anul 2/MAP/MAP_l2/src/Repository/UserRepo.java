package Repository;

import Domain.User;

import java.util.ArrayList;

public class UserRepo {
    ArrayList<User> users;
    String fileName;

    public UserRepo(String fileName) {
        /**
         * Constructor of UserRepo class
         *
         * @param fileName: the name of the file where the users are stored
         * @param users: the list of users
         */
        this.fileName = fileName;
        this.users = new ArrayList<>();
    }

    public void addUser(User user) {
        /**
         * Adds a user to the list of users
         *
         * @param user: the user to be added
         */
        users.add(user);
    }

    public boolean exists(int id){
        /**
         * Checks if a user with the given id exists in the list of users
         *
         * @param id: the id of the user to be checked
         * @return true if the user exists, false otherwise
         */
        for(User user: users){
            if(user.getId() == id){
                return true;
            }
        }
        return false;
    }

    public boolean exists(String u){
        /**
         * Checks if a user with the given id exists in the list of users
         *
         * @param id: the id of the user to be checked
         * @return true if the user exists, false otherwise
         */
        for(User user: users){
            if(user.getName().equals(u)){
                return true;
            }
        }
        return false;
    }

    public ArrayList<User> getAllUsers() {
        /**
         * Returns the list of users
         *
         * @return the list of users
         */
        return users;
    }

    public void removeUser(int Id) {
        /**
         * Removes a user from the list of users
         *
         * @param Id: the id of the user to be removed
         */
        users.removeIf(user -> user.getId() == Id);
    }
}
