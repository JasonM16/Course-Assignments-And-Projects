/**
 * PROJECT:     Lab 2 - Question 1
 * FILE:        Q1Arithmetic.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Debug a program and comment on the changes made.
 */


import javax.swing.JOptionPane; // edit 1: move import above class definition


public class Q1Arithmetic {

    public static void main(String args[]){
        String firstNumber, secondNumber, thirdNumber;
        int num1, // edit 2: added a new variable, num1
            num2, num3, sum, product, average;

        // edit 3: removed equality operator with assignment operator for the six statements below
        //****************************************************************************************
        firstNumber  = JOptionPane.showInputDialog("Enter first integer:");  // edit 3.1: added semi-colon
        secondNumber = JOptionPane.showInputDialog("Enter second integer:"); // edit 3.1: added semi-colon
        thirdNumber  = JOptionPane.showInputDialog("Enter third integer:");  // edit 3.1: added semi-colon
        num1         = Integer.parseInt(firstNumber);
        num2         = Integer.parseInt(secondNumber);
        num3         = Integer.parseInt(thirdNumber);
        //****************************************************************************************

        sum          = num1 + num2 + num3;
        product      = num1 * num2 * num3;
        average      = sum/3; // edit 4: use sum variable

        String result = "The sum is " + sum + "\nThe product is " + product +
                        "\nThe average is " + average;

        JOptionPane.showMessageDialog(null, result, "Results", JOptionPane.PLAIN_MESSAGE);
    }
} // end class Q1Arithmetic
