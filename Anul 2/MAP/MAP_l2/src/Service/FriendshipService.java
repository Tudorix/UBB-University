package Service;

import Domain.Friendship;
import Domain.User;
import Exceptions.DuplicateException;
import Exceptions.EntityNotFoundException;
import Repository.FriendshipRepo;
import Repository.Repository;
import Repository.UserRepo;
import Utils.AdjacentGraph;
import Utils.Graph;
import Validator.Validator;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class FriendshipService {
    Repository<Integer, Friendship> friendshipRepo;
    UserService userService;

    public FriendshipService(Repository<Integer, Friendship> friendshipRepo, UserService userService) {
        /**
         * Constructor of FriendshipService class
         *
         * @param friendshipRepo: the repository of friendships
         * @param userService: the service of users
         * @param validator: the validator of friendships
         */
        this.friendshipRepo = friendshipRepo;
        this.userService = userService;
    }

    public Iterable<Friendship> getAllFriendships() {
        /**
         * Returns the list of friendships
         *
         * @return the list of friendships
         */
        return friendshipRepo.findAll();
    }

    public int comunities(){
        /**
         * Returns the number of communities in the social network
         *
         * @return the number of communities
         */
        Graph graph = new AdjacentGraph();
        for(Friendship friendship: friendshipRepo.findAll()){
            graph.addEdge(friendship.getUser1(), friendship.getUser2());
        }
        return graph.getConnectedComponents();
    }

    public List<String> largestCommunity(){
        /**
         * Returns the largest community in the social network
         *
         * @return the largest community
         */
        Graph graph = new AdjacentGraph();
        for(Friendship friendship: friendshipRepo.findAll()){
            graph.addEdge(friendship.getUser1(), friendship.getUser2());
        }
        List<String> largestComponent = graph.getLargestConnectedComponent();
        return largestComponent;
    }

    public void addFriendship(int id, String u1, String u2, LocalDateTime dateTime) {
        /**
         * Adds a friendship between two users
         *
         * @param id: the id of the friendship
         * @param u1: the username of the first user
         * @param u2: the username of the second user
         *
         * @throws EntityNotFoundException if one of the users does not exist
         * @throws DuplicateException if the friendship already exists
         */

        Friendship friendship = new Friendship(id,u1,u2, dateTime);

        if(!userService.exists(u1)) {
            throw new EntityNotFoundException("User with id " + u1 + " not found");
        }
        if(!userService.exists(u2)) {
            throw new EntityNotFoundException("User with id " + u2 + " not found");
        }
        if(friendshipRepo.findOne(id) != null) {
            throw new DuplicateException("Friendship with id " + id + " already exists");
        }
        if(existsFriendship(u1, u2)) {
            throw new DuplicateException("Friendship between users " + u1 + " and " + u2 + " already exists");
        }
        friendshipRepo.save(friendship);
    }

    public boolean existsFriendship(String user1, String user2) {
        for (Friendship f : friendshipRepo.findAll()) {
            if ((f.getUser1().equals(user1) && f.getUser2().equals(user2)) ||
                    (f.getUser1().equals(user2) && f.getUser2().equals(user1))) {
                return true;
            }
        }
        return false;
    }

    public void removeFriendship(int id) {
        /**
         * Removes a friendship between two users
         *
         * @param id: the id of the friendship
         *
         * @throws EntityNotFoundException if the friendship does not exist
         */
        if(friendshipRepo.findOne(id) == null) {
            throw new EntityNotFoundException("Friendship with id " + id + " not found");
        }
        friendshipRepo.delete(id);
    }
}
