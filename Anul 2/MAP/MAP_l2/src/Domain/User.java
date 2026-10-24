package Domain;

import java.net.IDN;

public class User extends Entity<Integer>{
    String name;
    String email;
    int age;

    public User(String name, String email, int age, int id) {
        /**
         * Constructor for the User class
         *
         * @param name: the name of the user
         * @param email: the email of the user
         * @param age: the age of the user
         * @param id: the id of the user
         */
        super(id);
        this.name = name;
        this.email = email;
        this.age = age;
    }

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", age=" + age +
                ", id=" + super.getId() +
                '}';
    }

    public int getAge() {
        return age;
    }

    public Integer getId() {
        return super.getId();
    }

    public String getEmail() {
        return email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
