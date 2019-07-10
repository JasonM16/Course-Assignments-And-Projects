/**
 * PROJECT:     Lab 2 - Question 4
 * FILE:        Q4Patterns.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Write an application that displays the following patterns separately,
 *              one below the other. Use for loops to generate the patterns. All asterisks (*) should be printed by a
 *              single statement of the form System.out.print( '*' ) ( which causes the asterisks to print side by side),
 *              or a statement of the form System.out.println() (which can be used to position to the next line),
 *              or a statement of the form System.out.print( ' ' ) (which can be used to display a space for the last
 *              two patterns). There should be no other output statements in the program.
 *
 *              ** Not sure which type of pattern to print out. Assignment description was slightly ambiguous so I
 *                 wrote two different methods: **
 *
 *              Type1:                                      Type2:
 *
 *              *                   **********              *
 *              **                  *********               **
 *              ***                 ********                ***
 *              ****                *******                 ****
 *              *****               ******                  *****
 *              ******              *****                   ******
 *              *******             ****                    *******
 *              ********            ***                     ********
 *              *********           **                      *********
 *              **********          *                       **********
 *                                                          **********
 *                                                          *********
 *                                                          ********
 *                                                          *******
 *                                                          ******
 *                                                          *****
 *                                                          ****
 *                                                          ***
 *                                                          **
 *                                                          *
 */


public class Q4Patterns {

    private static String pattern = "*";   // for different patterns to print out
    private static String newLine = "\n";  // newline character
    private static int height     = 20;    // how many levels to print

    public static void main(String[] args){
        printPattern("Type 1:", 1);
        printPattern(newLine, 2);
        PrintType1(height);
        printPattern(newLine, 2);
        printPattern("Type 2:", 1);
        printPattern(newLine, 1);
        PrintType2(height);
    }


    private static void PrintType1(int height) {

        int i = 1;
        int j = height + 1;
        int space = height * 2;

        for (int k = 0; k <= height; k++, i++, j--, space--){
            printPattern(pattern, i);
            printPattern(" ", space);
            printPattern(pattern, j);
            printPattern(newLine, 1);
        }
    }


    private static void PrintType2(int height) {

        int i;
        for(i = 0; i <= height; i++) {
            printPattern(pattern, i);
            printPattern(newLine, 1);
        }
        for(i--; i >= 0; i--) {
            printPattern(pattern, i);
            printPattern(newLine, 1);
        }
    }


    static void printPattern(String pattern, int iterations)
    {
        for(int i = 0; i < iterations; i++)
            System.out.print(pattern);
    }

} // end class Q4Patterns
