package Repository;

import Domain.Friendship;
import Validator.Validator;

import java.util.ArrayList;

public class FriendshipRepo {
    ArrayList<Friendship> friendships;
    String fileName;

    public FriendshipRepo(String fileName) {
        /**
         * Constructor of FriendshipRepo class
         *
         * @param fileName: the name of the file where the friendships are stored
         * @param friendships: the list of friendships
         */
        this.fileName = fileName;
        this.friendships = new ArrayList<>();
    }

    public ArrayList<Friendship> getAllFriendships() {
        /**
         * Returns the list of friendships
         *
         * @return the list of friendships
         */
        return friendships;
    }

    public void addFriendship(Friendship friendship) {
        /**
         * Adds a friendship to the list of friendships
         *
         * @param friendship: the friendship to be added
         */
        friendships.add(friendship);
    }

    public void removeFriendship(int id) {
        /**
         * Removes a friendship from the list of friendships
         *
         * @param id: the id of the friendship to be removed
         */
        friendships.removeIf(friendship -> friendship.getId() == id);
    }

    public boolean exists(int id){
        /**
         * Checks if a friendship with the given id exists in the list of friendships
         *
         * @param id: the id of the friendship to be checked
         * @return true if the friendship exists, false otherwise
         */
        for(Friendship friendship: friendships){
            if(friendship.getId() == id){
                return true;
            }
        }
        return false;
    }

    public boolean existsFriendship(int id1, int id2){
        /**
         * Checks if a friendship between the two users with the given ids
         * exists in the list of friendships
         *
         * @param id1: the id of the first user
         * @param id2: the id of the second user
         * @return true if the friendship exists, false otherwise
         */
        for(Friendship friendship: friendships){
            if((friendship.getUser1Id() == id1 && friendship.getUser2Id() == id2) || (friendship.getUser1Id() == id2 && friendship.getUser2Id() == id1)){
                return true;
            }
        }
        return false;
    }
}
