/**
 * PROJECT:     Lab 2 - Question 8
 * FILE:        Q8ReplaceText.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Write a program that starts with a line of text and then outputs that line of text with the first
                occurrence of "hate" changed to "love". For example, a possible sample output might be:

                    The line of text to be changed is:
                    I hate you.
                    I have rephrased that line to read:
                    I love you.

                You can assume that the word "hate" occurs in the input. If the word "hate" occurs more than once in
                the line, your program will replace only the first occurrence of "hate".
 */


public class Q8ReplaceText {

    public static void main(String[] args) {

        String replacementText = "I hate you.";
        System.out.print("The line of text to be changed is:\n" + replacementText);
        System.out.print("\nI have rephrased that line to read: \n" + replacementText.replaceFirst("hate", "love"));
    }
} // end class Q8ReplaceText
