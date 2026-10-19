package Task;

import java.util.Objects;

public abstract class Task {
    private String taskId;
    private String description;

    public Task(String taskId, String description){
        this.taskId = taskId;
        this.description = description;
    }

    public String getTaskId(){
        return this.taskId;
    }

    public String getDescription(){
        return this.description;
    }

    public abstract void execute();

    @Override
    public String toString() {
        return "Task{" +
                "taskId='" + taskId + '\'' +
                ", description='" + description + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Task task = (Task) o;
        return Objects.equals(taskId, task.taskId) && Objects.equals(description, task.description);
    }

    @Override
    public int hashCode() {
        return Objects.hash(taskId, description);
    }
}
