import Task.MessageTask;

import java.time.LocalDateTime;

public class Main {
    public static void main(String[] args) {
        MessageTask mt1 = new MessageTask(
                "1",
                "Message",
                "A message",
                "6",
                "7",
                LocalDateTime.now()
        );


    }
}