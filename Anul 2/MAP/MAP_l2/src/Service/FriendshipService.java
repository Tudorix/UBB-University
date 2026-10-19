package Service;

import Domain.Friendship;
import Domain.User;
import Exceptions.DuplicateException;
import Exceptions.EntityNotFoundException;
import Repository.FriendshipRepo;
import Repository.UserRepo;
import Utils.AdjacentGraph;
import Utils.Graph;
import Validator.Validator;

import java.util.ArrayList;
import java.util.List;

public class FriendshipService {
    FriendshipRepo friendshipRepo;
    UserRepo userRepo;
    Validator<Friendship> validator;

    public FriendshipService(FriendshipRepo friendshipRepo, UserRepo userRepo, Validator<Friendship> validator) {
        /**
         * Constructor of FriendshipService class
         *
         * @param friendshipRepo: the repository of friendships
         * @param userRepo: the repository of users
         * @param validator: the validator of friendships
         */
        this.friendshipRepo = friendshipRepo;
        this.userRepo = userRepo;
        this.validator = validator;
    }

    public ArrayList<Friendship> getAllFriendships() {
        /**
         * Returns the list of friendships
         *
         * @return the list of friendships
         */
        return friendshipRepo.getAllFriendships();
    }

    public int comunities(){
        /**
         * Returns the number of communities in the social network
         *
         * @return the number of communities
         */
        Graph graph = new AdjacentGraph();
        for(Friendship friendship: friendshipRepo.getAllFriendships()){
            graph.addEdge(friendship.getUser1Id(), friendship.getUser2Id());
        }
        return graph.getConnectedComponents();
    }

    public List<User> largestCommunity(){
        /**
         * Returns the largest community in the social network
         *
         * @return the largest community
         */
        Graph graph = new AdjacentGraph();
        for(Friendship friendship: friendshipRepo.getAllFriendships()){
            graph.addEdge(friendship.getUser1Id(), friendship.getUser2Id());
        }
        List<Integer> largestComponent = graph.getLargestConnectedComponent();
        List<User> users = new ArrayList<>();
        for(Integer id: largestComponent){
            for(User user: userRepo.getAllUsers()){
                if(user.getId() == id){
                    users.add(user);
                }
            }
        }
        return users;
    }

    public void addFriendship(int id, int id1, int id2) {
        /**
         * Adds a friendship between two users
         *
         * @param id: the id of the friendship
         * @param id1: the id of the first user
         * @param id2: the id of the second user
         *
         * @throws EntityNotFoundException if one of the users does not exist
         * @throws DuplicateException if the friendship already exists
         */
        Friendship friendship = new Friendship(id,id1,id2);
        validator.validate(friendship);
        if(!userRepo.exists(id1)) {
            throw new EntityNotFoundException("User with id " + id1 + " not found");
        }
        if(!userRepo.exists(id2)) {
            throw new EntityNotFoundException("User with id " + id2 + " not found");
        }
        if(friendshipRepo.exists(id)) {
            throw new DuplicateException("Friendship with id " + id + " already exists");
        }
        if(friendshipRepo.existsFriendship(id1, id2)) {
            throw new DuplicateException("Friendship between users " + id1 + " and " + id2 + " already exists");
        }
        friendshipRepo.addFriendship(friendship);
    }

    public void removeFriendship(int id) {
        /**
         * Removes a friendship between two users
         *
         * @param id: the id of the friendship
         *
         * @throws EntityNotFoundException if the friendship does not exist
         */
        if(!friendshipRepo.exists(id)) {
            throw new EntityNotFoundException("Friendship with id " + id + " not found");
        }
        friendshipRepo.removeFriendship(id);
    }
}
