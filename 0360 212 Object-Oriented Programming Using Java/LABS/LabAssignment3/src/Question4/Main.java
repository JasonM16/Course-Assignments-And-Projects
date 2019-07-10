/**
 * PROJECT:         Lab 3 - Question 4
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 8, 2017
 * DESCRIPTION:     This program prints a square of asterisks to the console with size of the square
 *                  given by the user.
 */


package Question4;
import javax.swing.*;


public class Main {

    public static void main(String[] args) {

        String input = JOptionPane.showInputDialog("What size of square would you like? :  ");
        int size = Integer.parseInt(input);
        squareOfAsterisks(size);
    }




    /******************************************************************************
     METHOD		    : squareOfAsterisks

     DESCRIPTION	: This method prints a square of asterisks to the console.

     INPUT			: Type			: int
                    : Description	: the size of square to print.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public static void squareOfAsterisks(int size){

        int lineCounter = 1;
        for (int i = 0; i < size * size; i++) {
            System.out.print("* ");
            if(lineCounter == size ) {
                System.out.println("");
                lineCounter = 0;
            }

            lineCounter++;
        }
    }
}

