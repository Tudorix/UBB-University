package Operations;

import Complex.ComplexNumber;

public class Subtraction implements Operation{
    @Override
    public ComplexNumber execute(ComplexNumber a, ComplexNumber b) {
        return new ComplexNumber(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
    }
}
