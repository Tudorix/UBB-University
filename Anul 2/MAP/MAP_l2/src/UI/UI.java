package UI;

import Domain.Friendship;
import Domain.User;
import Service.FriendshipService;
import Service.UserService;

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
        /**
         * Starts the UI
         */

        // Users
        userService.addUser("Alice", "alice@example.com", 25, 1);
        userService.addUser("Bob", "bob@example.com", 30, 2);
        userService.addUser("Charlie", "charlie@example.com", 35, 3);
        userService.addUser("David", "david@example.com", 22, 4);
        userService.addUser("Emma", "emma@example.com", 28, 5);
        userService.addUser("Frank", "frank@example.com", 31, 6);
        userService.addUser("Grace", "grace@example.com", 24, 7);
        userService.addUser("Henry", "henry@example.com", 27, 8);
        userService.addUser("Ivy", "ivy@example.com", 23, 9);
        userService.addUser("Jack", "jack@example.com", 29, 10);
        userService.addUser("Kate", "kate@example.com", 26, 11);
        userService.addUser("Leo", "leo@example.com", 32, 12);
        userService.addUser("Mia", "mia@example.com", 21, 13);
        userService.addUser("Noah", "noah@example.com", 33, 14);
        userService.addUser("Olivia", "olivia@example.com", 25, 15);
        friendshipService.addFriendship(1, 1, 2);
        friendshipService.addFriendship(2, 2, 3);
        friendshipService.addFriendship(3, 3, 4);
        friendshipService.addFriendship(4, 4, 5);
        friendshipService.addFriendship(5, 6, 7);
        friendshipService.addFriendship(6, 7, 8);
        friendshipService.addFriendship(7, 8, 9);
        friendshipService.addFriendship(8, 6, 9);
        friendshipService.addFriendship(9, 10, 11);
        friendshipService.addFriendship(10, 11, 12);
        friendshipService.addFriendship(11, 12, 13);
        friendshipService.addFriendship(12, 14, 15);

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
                        ArrayList<User> users = userService.getAllUsers();
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
                        System.out.println("Enter friendship details (id,user1Id,user2Id):");
                        String[] friendshipDetails = scanner.nextLine().split(",");
                        int fid = Integer.parseInt(friendshipDetails[0]);
                        int user1Id = Integer.parseInt(friendshipDetails[1]);
                        int user2Id = Integer.parseInt(friendshipDetails[2]);
                        friendshipService.addFriendship(fid, user1Id, user2Id);
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
                        ArrayList<Friendship> friendships = friendshipService.getAllFriendships();
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
                        List<User> largestCommunity = friendshipService.largestCommunity();
                        System.out.println("Largest community:");
                        for (User user : largestCommunity) {
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

