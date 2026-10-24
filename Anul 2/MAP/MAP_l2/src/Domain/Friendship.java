package Domain;

import java.time.LocalDateTime;
import java.util.Date;

public class Friendship extends Entity<Integer> {
    private String user1;
    private String user2;
    private LocalDateTime date;

    public Friendship(int id, String user1, String user2, LocalDateTime date) {
        /**
         * Constructor of the Friendship class
         *
         * @param id the unique identifier of the friendship
         * @param user1Id the ID of the first user
         * @param user2Id the ID of the second user
         */
        super(id);
        this.user1 = user1;
        this.user2 = user2;
        this.date = date;
    }

    @Override
    public String toString() {
        return "Friendship{" +
                "id=" + super.getId() +
                ", user1=" + user1 +
                ", user2=" + user2 +
                ", date=" + date +
                '}';
    }

    public String getUser1() {
        return user1;
    }

    public String getUser2() {
        return user2;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public Integer getId() {
        /**
         * Returns the unique identifier of the friendship.
         *
         * @return the unique identifier of the friendship
         */
        return super.getId();
    }
}
