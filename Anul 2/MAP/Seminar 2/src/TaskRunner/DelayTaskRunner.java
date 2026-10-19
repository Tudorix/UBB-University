package TaskRunner;

public class DelayTaskRunner extends AbstractTaskRunner{

    public DelayTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeAll(){
        while(super.hasTask()){
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            super.executeOne();
        }
    }

}
