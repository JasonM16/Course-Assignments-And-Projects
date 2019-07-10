/**
 * PROJECT:         Lab 3 - Question 3
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 8, 2017
 * DESCRIPTION:     This class represents a fraction (rational or irrational number).
 */


package Question3;


public class Fraction {

    // member variables
    private final int numerator;
    private final int denominator;





    /******************************************************************************
     CONSTRUCTOR    : Fraction

     DESCRIPTION	: Builds a new fraction.

     INPUT			: Type			: int
                    : Description	: The numerator.

                    : Type			: int
                    : Description	: The denominator.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Fraction(int n, int d) {
        numerator   = n;
        denominator = d;
    }





    // Getters
    public int Denominator() {
        return denominator;
    }
    public int Numerator() {
        return numerator;
    }







    /******************************************************************************
     METHOD		    : calculateDecimalExpansion

     DESCRIPTION	: This method calculates and returns the decimal expansion of
                      the fraction.

     INPUT			: Type			: int
                    : Description	: The numerator.

                    : Type			: int
                    : Description	: The denominator.

     OUTPUT			: Type 			: double
                    : Description	: The decimal expansion of the fraction.
     ******************************************************************************/
    public static double calculateDecimalExpansion(int numerator, int denominator) {

        return numerator/(double)denominator;
    }





    /******************************************************************************
     METHOD		    : calculateFraction

     DESCRIPTION	: This method calculates and returns a fraction in lowest terms.

     INPUT			: Type			: int
                    : Description	: The numerator.

                    : Type			: int
                    : Description	: The denominator.

     OUTPUT			: Type 			: Fraction
                    : Description	: The fraction in reduced terms.
     ******************************************************************************/
    public static Fraction calculateFraction(int numerator, int denominator) {

        int gcd = greatestCommonDivisor(numerator, denominator);

        numerator   /= gcd;
        denominator /= gcd;

        return new Fraction(numerator, denominator);
    }





    /******************************************************************************
     METHOD		    : greatestCommonDivisor

     DESCRIPTION	: This method calculates the greatest common divisor of a
                      fraction.

     INPUT			: Type			: int
                    : Description	: The numerator.

                    : Type			: int
                    : Description	: The denominator.

     OUTPUT			: Type 			: int
                    : Description	: The GCD (numerator).
     ******************************************************************************/
    public static int greatestCommonDivisor(int numerator, int denominator) {

        while(denominator > 0) {
            int temp = denominator;
            denominator = numerator % denominator;
            numerator = temp;
        }

        return numerator;
    }
}

