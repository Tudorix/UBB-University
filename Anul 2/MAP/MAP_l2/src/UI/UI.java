package UI;

import Domain.Friendship;
import Domain.User;
import Service.FriendshipService;
import Service.UserService;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class UI {
    UserService userService;
    FriendshipService friendshipService;
    boolean running = true;
    Scanner scanner = new Scanner(System.in);

    public UI(UserService userService, FriendshipService friendshipService) {
        /**
         * Constructor of UI class
         *
         * @param userService: the service of users
         * @param friendshipService: the service of friendships
         */
        this.friendshipService = friendshipService;
        this.userService = userService;
    }

    public void start() {

        while (running) {
            System.out.println("1. Add User");
            System.out.println("2. Remove User");
            System.out.println("3. List Users");
            System.out.println("4. Add Friendship");
            System.out.println("5. Remove Friendship");
            System.out.println("6. List Friendships");
            System.out.println("7. Number of communities");
            System.out.println("8. Largest community");
            System.out.println("0. Exit");

            String option = scanner.nextLine();
            switch (option) {
                case "1":
                    try {
                        System.out.println("Enter user details (name,email,age,id):");
                        String[] userDetails = scanner.nextLine().split(",");
                        String name = userDetails[0];
                        String email = userDetails[1];
                        int age = Integer.parseInt(userDetails[2]);
                        int id = Integer.parseInt(userDetails[3]);
                        userService.addUser(name, email, age, id);
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "2":
                    try {
                        System.out.println("Enter user id to remove User:");
                        int removeId = Integer.parseInt(scanner.nextLine());
                        userService.removeUser(removeId);
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "3":
                    try{
                        System.out.println("List of users:");
                        Iterable<User> users = userService.getAllUsers();
                        for (User user : users) {
                            System.out.println(user);
                        }
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "4":
                    try{
                        System.out.println("Enter friendship details (id,user1Id,user2Id,date):");
                        String[] friendshipDetails = scanner.nextLine().split(",");
                        int fid = Integer.parseInt(friendshipDetails[0]);
                        String user1Id = friendshipDetails[1];
                        String user2Id = friendshipDetails[2];
                        LocalDateTime date = LocalDateTime.parse(friendshipDetails[3])
;                        friendshipService.addFriendship(fid, user1Id, user2Id,date);
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "5":
                    try {
                        System.out.println("Enter friendship id (id):");
                        String[] removeFriendshipDetails = scanner.nextLine().split(",");
                        int fremoveid = Integer.parseInt(removeFriendshipDetails[0]);
                        friendshipService.removeFriendship(fremoveid);
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "6":
                    try {
                        Iterable<Friendship> friendships = friendshipService.getAllFriendships();
                        for (Friendship friendship : friendships) {
                            System.out.println(friendship);
                        }
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "0":
                    running = false;
                    break;
                case "7":
                    try {
                        int communities = friendshipService.comunities();
                        System.out.println("Number of communities: " + communities);
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case "8":
                    try {
                        List<String> largestCommunity = friendshipService.largestCommunity();
                        System.out.println("Largest community:");
                        for (var user : largestCommunity) {
                            System.out.println(user);
                        }
                    }
                    catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                    break;
            }
        }
    }
}

