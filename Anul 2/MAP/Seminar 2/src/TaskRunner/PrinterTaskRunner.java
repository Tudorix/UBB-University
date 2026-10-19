package TaskRunner;

public class PrinterTaskRunner extends AbstractTaskRunner{

    public PrinterTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeOne() {
        System.out.println("Executing one task...");
        super.executeOne();
    }
}
