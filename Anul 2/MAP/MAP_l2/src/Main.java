import Domain.Friendship;
import Domain.User;
import Exceptions.RepositoryException;
import Exceptions.ValidationException;
import Repository.FriendshipRepo;
import Repository.Repository;
import Repository.UserRepo;
import Repository.factory.RepositoryFactory;
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

        try {
            Validator<User> validatorU = new UserValidator();
            Validator<Friendship> validatorF = new FriendshipValidator();

            RepositoryFactory factory = new RepositoryFactory();

            Repository<Integer, User> userRepository =
                    factory.createUserRepository(validatorU);

            Repository<Integer, Friendship> friendshipRepository =
                    factory.createFriendshipRepository(validatorF, userRepository);

            UserService userService = new UserService(userRepository, friendshipRepository);
            FriendshipService friendshipService =
                    new FriendshipService(friendshipRepository, userService);

            UI ui = new UI(userService, friendshipService);
            ui.start();
        } catch (ValidationException | RepositoryException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}