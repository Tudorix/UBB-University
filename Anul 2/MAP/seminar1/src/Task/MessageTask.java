package Task;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task{

    private String message;
    private String from;
    private String to;
    private LocalDateTime time;

    public static final DateTimeFormatter DATE_TIME_FORMATTER = DateTimeFormatter.ofPattern("yyyy");

    public MessageTask(String taskId, String description, String message, String from, String to, LocalDateTime time) {
        super(taskId, description);
        this.message = message;
        this.from = from;
        this.to = to;
        this.time = time;
    }

    @Override
    public void execute() {
        System.out.println(toString());
    }

    @Override
    public String toString() {
        return "MessageTask{" +
                "message='" + message + '\'' +
                ", from='" + from + '\'' +
                ", to='" + to + '\'' +
                ", time=" + time.format(DATE_TIME_FORMATTER) +
                '}';
    }
}
