package Utils;

import Domain.User;

import java.util.function.Predicate;

public class CriteriiUser {
    public static Predicate<User> minAge(int age){
        return User -> User.getAge() >= age;
    }

    public static Predicate<User> prefix(char c){
        return User -> User.getName().startsWith(String.valueOf(c));
    }
}
