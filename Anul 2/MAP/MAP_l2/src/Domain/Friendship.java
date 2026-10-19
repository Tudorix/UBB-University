package Domain;

public class Friendship {
    private int id;
    private int user1Id;
    private int user2Id;

    public Friendship(int id, int user1Id, int user2Id) {
        /**
         * Constructor of the Friendship class
         *
         * @param id the unique identifier of the friendship
         * @param user1Id the ID of the first user
         * @param user2Id the ID of the second user
         */
        this.id = id;
        this.user1Id = user1Id;
        this.user2Id = user2Id;
    }

    @Override
    public String toString() {
        return "Friendship{" +
                "id=" + id +
                ", user1Id=" + user1Id +
                ", user2Id=" + user2Id +
                '}';
    }

    public int getUser2Id() {
        /**
         * Returns the ID of the second user in the friendship.
         *
         * @return the ID of the second user
         */
        return user2Id;
    }

    public int getUser1Id() {
        /**
         * Returns the ID of the first user in the friendship.
         *
         * @return the ID of the first user
         */
        return user1Id;
    }

    public int getId() {
        /**
         * Returns the unique identifier of the friendship.
         *
         * @return the unique identifier of the friendship
         */
        return id;
    }
}
