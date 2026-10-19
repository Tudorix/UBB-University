package Evaluation;

import Complex.ComplexNumber;
import Operations.Operation;

public class ExpressionEvaluator {
    Operation operation;

    public ExpressionEvaluator(Operation operation) {
        this.operation = operation;
    }

    public ComplexNumber evaluate(ComplexNumber[] numbers){
        ComplexNumber result = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            result = operation.execute(result, numbers[i]);
        }
        return result;
    }
}
