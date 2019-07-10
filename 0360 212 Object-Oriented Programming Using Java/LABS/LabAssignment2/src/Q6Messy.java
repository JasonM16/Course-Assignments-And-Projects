/**
 * PROJECT:     Lab 2 - Question 6
 * FILE:        Q6Messy.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Modify the program so that it uses the spelling conventions, constant naming conventions, and proper
 *              formatting style.
 */


public class Q6Messy { // messy - lowercase

    public static final double distance = 6.21; // moved up

    public static void main(String[] args) { // use proper indentation throughout

        // variables: lowercase. Declaration and definition on same line
        double time = 35.5; // 35 minutes and 30 seconds
        double pace = time / distance;

        System.out.println("This program calculates your pace given a time and distance traveled.");
        System.out.printf("Your pace is %.2f miles per hour.", pace); // format to 2 decimal places
    }

} // end class Q6Messy
