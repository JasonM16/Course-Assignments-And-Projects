/**
 * PROJECT:         Lab 3 - Question 5
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette 104337378
 * LAST MODIFIED:   February 8, 2017
 * DESCRIPTION:     This program accepts three numbers from the user and determines the smallest one.
 */


package Question5;
import javax.swing.*;


public class Main {

    public static void main(String[] args) {

        String input = JOptionPane.showInputDialog("Enter the first number : ");
        float a = Float.parseFloat(input);

        input = JOptionPane.showInputDialog("Enter the second number : ");
        float b =  Float.parseFloat(input);

        input = JOptionPane.showInputDialog("Enter the third number : ");
        float c =  Float.parseFloat(input);

        float min = minimum3(a, b, c);

        String result = "The smallest of " + a + ", " + b + " and " + c + " is " + min;

        JOptionPane.showMessageDialog(null, result);
    }





    /******************************************************************************
     METHOD		    : minimum3

     DESCRIPTION	: This method uses Java's built-in min function to compare three
                      numbers and return the minimum number.

     INPUT			: Type			: float
                    : Description	: The first number to compare.

                    : Type			: float
                    : Description	: The second number to compare.

                    : Type			: float
                    : Description	: The third number to compare.

     OUTPUT			: Type 			: float
                    : Description	: the smallest of the three numbers.
     ******************************************************************************/
    static float minimum3(float a, float b, float c) {

        return Math.min(Math.min(a,b), c);
    }
}
