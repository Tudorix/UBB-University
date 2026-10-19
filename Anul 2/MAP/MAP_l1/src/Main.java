import Complex.ComplexNumber;
import Evaluation.ExpressionEvaluator;
import Operations.Addition;
import Operations.Division;
import Operations.Multiplication;
import Parsing.ExpressionParser;
import Operations.Operation;
import Operations.Subtraction;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        if(args.length == 0) {
            System.out.println("Please provide a valid expression as command line arguments.");
            return;
        }

        try{
            ExpressionParser parser = new ExpressionParser();
            parser.parse(args);
            ComplexNumber[] numbers = parser.getNumbers();
            String operator = parser.getOperator();

            Operation operation;
            switch (operator) {
                case "+":
                    operation = new Addition();
                    break;
                case "-":
                    operation = new Subtraction();
                    break;
                case "*":
                    operation = new Multiplication();
                    break;
                case "/":
                    operation = new Division();
                    break;
                default:
                    throw new IllegalArgumentException("Unsupported operator: " + operator);
            }

            ExpressionEvaluator evaluator = new ExpressionEvaluator(operation);
            ComplexNumber result = evaluator.evaluate(numbers);
            if(result.getImaginary() >= 0) {
                System.out.println("Result: " + result.getReal() + " + " + result.getImaginary() + "*i");
            } else {
                System.out.println("Result: " + result.getReal() + " - " + Math.abs(result.getImaginary()) + "*i");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}