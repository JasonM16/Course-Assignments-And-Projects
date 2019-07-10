/**
 * PROJECT:         Lab 3 - Question 7
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 8, 2017
 * DESCRIPTION:
 */

package Question7;


public class Main {

    public static void main(String[] args) {

        // Create tow complex number instances
        ComplexNumber c1 = new ComplexNumber( 3, 4);
        ComplexNumber c2 = new ComplexNumber(19, 83);

        System.out.println(c1);
        System.out.println(c2);
        System.out.println(new ComplexNumber());

        // print the results of adding and subtracting the two
        // complex numbers...
        System.out.println(c1 + " + " + c2 + " = " + c1.Add(c2));
        System.out.println(c1 + " - " + c2 + " = " + c1.Subtract(c2));
    }
}
