/**
 * PROJECT:         Lab 3 - Question 7
 * FILE:            ComplexNumber.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 9, 2017
 * DESCRIPTION:     This class represents a complex number type and performs addition
 *                  and subtraction of two complex numbers.
 */


package Question7;


public class ComplexNumber {

    // member variables
    private float real;
    private float imaginary;


    /******************************************************************************
     CONSTRUCTOR    : ComplexNumber

     DESCRIPTION	: This is the default constructor to build a complex number.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public ComplexNumber() { this(1, 3); }





    /******************************************************************************
     CONSTRUCTOR    : ComplexNumber

     DESCRIPTION	: This constructor builds a complex number.

     INPUT			: Type			: float
                    : Description	: The real part.

                    : Type			: float
                    : Description	: The imaginary part.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public ComplexNumber(float re, float im){

        real = re;
        imaginary = im;
    }





    /******************************************************************************
     METHOD		    : Add

     DESCRIPTION	: This method adds two complex numbers and returns a new complex
                      number instance.

     INPUT			: Type			: ComplexNumber
                    : Description	: The second operand to add.

     OUTPUT			: Type 			: ComplexNumber
                    : Description	: The resulting complex number after addition.
     ******************************************************************************/
    public ComplexNumber Add(ComplexNumber right) {

        return new ComplexNumber(real + right.Real(), imaginary + right.Imaginary());
    }





    /******************************************************************************
     METHOD		    : Subtract

     DESCRIPTION	: This method subtracts two complex numbers and returns a new
                      complex number instance.

     INPUT			: Type			: ComplexNumber
                    : Description	: The second operand to subtract.

     OUTPUT			: Type 			: ComplexNumber
                    : Description	: The resulting complex number after subtraction.
     ******************************************************************************/
    public ComplexNumber Subtract(ComplexNumber right) {

        return new ComplexNumber(real - right.Real(), imaginary - right.Imaginary());
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: Prints a formatted complex number

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: The formatted text string.
     ******************************************************************************/
    public String toString() {

        return "(" + real + ", " + imaginary + "i)";
    }


    // Getters
    public float Imaginary() { return imaginary; }
    public float Real() { return real; }
}
