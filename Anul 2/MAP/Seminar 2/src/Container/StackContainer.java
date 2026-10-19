package Container;

import Task.Task;

public class StackContainer implements Container{
    private Task[] tasks;
    private int size;

    public StackContainer() {
        this.tasks = new Task[10];
        this.size = 0;
    }

    public Task remove() {
        if (size == 0) {
            return null;
        }
        Task task = tasks[size - 1];
        size--;
        return task;
    }

    public void add(Task task) {
        if (size == tasks.length) {
            Task[] newTasks = new Task[tasks.length * 2];
            for (int i = 0; i < size; i++) {
                newTasks[i] = tasks[i];
            }
            tasks = newTasks;
        }
        tasks[size] = task;
        size++;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
