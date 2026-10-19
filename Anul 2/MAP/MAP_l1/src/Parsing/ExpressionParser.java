package Parsing;

import Complex.ComplexNumber;

public class ExpressionParser {
    private ComplexNumber[] numbers;
    private String operator;

    public void parse(String[] args) {
        if (!isValidStructure(args)) {
            throw new IllegalArgumentException("Invalid expression structure");
        }

        numbers = new ComplexNumber[(args.length + 1) / 2];
        for(int i = 0; i < args.length; i += 2) {
            numbers[i / 2] = ComplexNumberParser.parse(args[i]);
        }

        operator = args[1];
    }

    private boolean isValidStructure(String[] args) {
        if (args == null || args.length < 3 || args.length % 2 == 0) {
            return false;
        }

        String firstOperator = args[1];

        for (int i = 1; i < args.length; i += 2) {
            if (!isValidOperator(args[i]) || !args[i].equals(firstOperator)) {
                return false;
            }
        }

        return true;
    }

    private boolean isValidOperator(String op) {
        if(op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/")) {
            return true;
        }
        return false;
    }

    public ComplexNumber[] getNumbers() {
        return numbers;
    }

    public String getOperator() {
        return operator;
    }
}
