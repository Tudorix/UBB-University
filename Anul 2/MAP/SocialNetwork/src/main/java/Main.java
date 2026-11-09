import Domain.Friendship;
import Domain.User;
import Exceptions.RepositoryException;
import Exceptions.ValidationException;
import Repository.Repository;
import Repository.factory.RepositoryFactory;
import Service.FriendshipService;
import Service.UserService;
import UI.UI;
import Utils.CriteriiUser;
import Validator.FriendshipValidator;
import Validator.UserValidator;
import Validator.Validator;

import java.util.function.Predicate;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        try {
            Validator<User> validator1 = new UserValidator();
            Validator<Friendship> validatorF = new FriendshipValidator();

            Validator<User> checkUsername = User -> {
              if(User.getName().length() < 3){
                  throw new ValidationException("Username not long enough!");
              }
            };

            Validator<User> validatorU = validator1.andThen(checkUsername);

            RepositoryFactory factory = new RepositoryFactory();

            Repository<Integer, User> userRepository =
                    factory.createUserRepository(validatorU);

            Repository<Integer, Friendship> friendshipRepository =
                    factory.createFriendshipRepository(validatorF, userRepository);

            UserService userService = new UserService(userRepository, friendshipRepository);
            FriendshipService friendshipService =
                    new FriendshipService(friendshipRepository, userService);

            /*
            Iterable<User> adults = userRepository.findAll(user -> user.getAge() >= 18);
            adults.forEach(System.out::println);

            Predicate<User> condition = CriteriiUser.minAge(20).negate().or(CriteriiUser.prefix('N'));

            Iterable<User> users = userRepository.findAll(condition);
            
             */

            UI ui = new UI(userService, friendshipService);
            ui.start();
        } catch (ValidationException | RepositoryException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}