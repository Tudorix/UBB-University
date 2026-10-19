package Parsing;

import Complex.ComplexNumber;

public class ComplexNumberParser {

    public static ComplexNumber parse(String input) {
        int separator = -1;

        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-') {
                separator = i;
                break;
            }
        }

        if (separator == -1) {
            throw new IllegalArgumentException("Invalid complex number format");
        }

        String real = input.substring(0, separator);
        String imaginary = input.substring(separator);

        if (!imaginary.endsWith("i")) {
            throw new IllegalArgumentException("Missing imaginary unit");
        }

        imaginary = imaginary.substring(0, imaginary.length() - 1);

        // Remove optional multiplication symbol
        if (imaginary.endsWith("*")) {
            imaginary = imaginary.substring(0, imaginary.length() - 1);
        }

        // Handle +i and -i
        if (imaginary.equals("+")) {
            imaginary = "1";
        } else if (imaginary.equals("-")) {
            imaginary = "-1";
        }

        double realPart = Double.parseDouble(real);
        double imaginaryPart = Double.parseDouble(imaginary);

        return new ComplexNumber(realPart, imaginaryPart);
    }
}
