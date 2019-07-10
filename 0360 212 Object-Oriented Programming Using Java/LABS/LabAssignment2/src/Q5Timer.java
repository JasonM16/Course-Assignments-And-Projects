/**
 * PROJECT:     Lab 2 - Question 5
 * FILE:        Q5Timer.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Write a program that outputs the number of hours, minutes, and seconds that corresponds to 50,391 total
 *              seconds. The output should be 13 hours, 59 minutes, and 51 seconds.
 */


public class Q5Timer {

    public static void main(String[] args){

        int totalSeconds = 50391;
        int hours        = totalSeconds / 60 /60;
        int minutes      = totalSeconds / 60 % 60;
        int seconds      = totalSeconds % 60;

        System.out.print(hours + " hours, " + minutes + " minutes, and " + seconds + " seconds.");
    }
} // end class Q5Timer
