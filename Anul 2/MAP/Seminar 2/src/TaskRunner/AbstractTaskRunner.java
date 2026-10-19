package TaskRunner;

public abstract class AbstractTaskRunner implements TaskRunner {

    private TaskRunner taskRunner;

    public AbstractTaskRunner(TaskRunner taskRunner) {
        this.taskRunner = taskRunner;
    }

    @Override
    public void addTask(Runnable task) {
        taskRunner.addTask(task);
    }

    @Override
    public void executeAll() {
        taskRunner.executeAll();
    }

    @Override
    public void executeOne() {
        taskRunner.executeOne();
    }

    @Override
    public boolean hasTask() {
        return taskRunner.hasTask();
    }

}
