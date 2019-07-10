/**
 * PROJECT:         Lab 3 - Question 3
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 8, 2017
 * DESCRIPTION:
 */



package Question3;
import javax.swing.*;
import java.util.Formatter;



public class Main {

    public static void main(String[] args) {

        Fraction fraction = getValuesFromUser();
        Fraction reduced = Fraction.calculateFraction(fraction.Numerator(), fraction.Denominator());

        Formatter formatter = new Formatter();
        formatter.format("The decimal expansion of %d and %d is %f \n",
                fraction.Numerator(), fraction.Denominator(),
                Fraction.calculateDecimalExpansion(fraction.Numerator(),
                 fraction.Denominator()));

        // print the decimal expansion of the fraction
        System.out.println(formatter.toString());


        formatter = new Formatter();
        formatter.format("The reduced fraction of %d and %d is %d/%d \n",
                fraction.Numerator(), fraction.Denominator(),
                reduced.Numerator(), reduced.Denominator());

        // print the reduced fraction in lowest form
        System.out.println(formatter.toString());
    }





    /******************************************************************************
     METHOD		    : getValuesFromUser

     DESCRIPTION	: This method obtains a numerator and denominator from the
                      user and returns a new fraction.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: Fraction
                    : Description	: New fraction.
     ******************************************************************************/
    public static Fraction getValuesFromUser() {

        int numerator   = Integer.parseInt(JOptionPane.showInputDialog("Please enter the numerator: "));
        int denominator = Integer.parseInt(JOptionPane.showInputDialog("Please enter the denominator: "));
        return new Fraction(numerator, denominator);
    }
}
