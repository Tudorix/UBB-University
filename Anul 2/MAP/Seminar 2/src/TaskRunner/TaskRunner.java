package TaskRunner;

public interface TaskRunner {

    void addTask(Runnable task);
    void executeAll();
    void executeOne();
    boolean hasTask();
}
