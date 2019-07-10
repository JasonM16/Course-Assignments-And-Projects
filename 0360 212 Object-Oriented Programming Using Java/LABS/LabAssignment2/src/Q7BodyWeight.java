/**
 * PROJECT:     Lab 2 - Question 7
 * FILE:        Q7BodyWeight.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: A simple rule to estimate your ideal body weight is to allow 110 pounds for the first 5 feet of height
                and 5 pounds for each additional inch. Write a program with a variable for the height of a person in
                feet and another variable for the additional inches. Assume the person is at least 5 feet tall.
                For example, a person that is 6 feet and 3 inches tall would be represented with a variable that stores
                the number 6 and another variable that stores the number 3.
                Based on these values, calculate and output the ideal body weight.
 */


public class Q7BodyWeight {

    public static void main(String[] args) {

        int initialWeight = 110;
        int initialHeight   = 5;
        int increment       = 5;

        // test data
        int feet            = 6;
        int inches          = 3;

        // 6'3" - 5'0" = 15 inches * 5 pounds = 75 pounds + initialWeight of 110 = 185 pounds

        int totalInches = ((feet - initialHeight) * 12) + inches;
        int totalWeight = initialWeight + (totalInches*increment);

        System.out.print("Total weight: " + totalWeight + " pounds.");
    }
} // end class Q7BodyWeight
