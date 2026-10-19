import Domain.Friendship;
import Domain.User;
import Repository.FriendshipRepo;
import Repository.UserRepo;
import Service.FriendshipService;
import Service.UserService;
import UI.UI;
import Validator.Validator;
import Validator.UserValidator;
import Validator.FriendshipValidator;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        String fileName = "users.csv";
        UserRepo repo = new UserRepo(fileName);
        Validator<User> validator = new UserValidator();
        UserService srv = new UserService(repo, validator);

        FriendshipRepo friendshipRepo = new FriendshipRepo("friendships.csv");
        Validator<Friendship> friendshipValidator = new FriendshipValidator();
        FriendshipService friendshipService = new FriendshipService(friendshipRepo,repo,friendshipValidator);

        UI ui = new UI(srv, friendshipService);
        ui.start();
    }
}