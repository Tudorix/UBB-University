package Domain;

public class User {
    String name;
    String email;
    int age;
    int id;

    public User(String name, String email, int age, int id) {
        /**
         * Constructor for the User class
         *
         * @param name: the name of the user
         * @param email: the email of the user
         * @param age: the age of the user
         * @param id: the id of the user
         */
        this.name = name;
        this.email = email;
        this.age = age;
        this.id = id;
    }

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", age=" + age +
                ", id=" + id +
                '}';
    }

    public int getAge() {
        return age;
    }

    public int getId() {
        return id;
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
