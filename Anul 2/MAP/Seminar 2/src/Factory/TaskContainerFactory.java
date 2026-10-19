package Factory;

import java.awt.*;
import java.util.Queue;
import containers.QueueConteiner;
import containers.StackContainer;

public class TaskContainerFactory implements Factory{

    private static TaskContainerFactory instance = null;


    private TaskContainerFactory(){

    }

    @Override
    public Container createContainer(Strategy strategy){
        if(strategy == Strategy.LIFO){
            return new StackContainer();
        }
        return new QueueConteiner();
    }

    public static TaskContainerFactory getInstance(){
        if(instance == null){
            return new TaskContainerFactory();
        }
        return instance;
    }
}
