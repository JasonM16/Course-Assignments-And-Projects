 /**
 * PROJECT:         Lab 3 - Question 6
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 8, 2017
 * DESCRIPTION:     This program asks the user to guess a number between 1 and 1000. The answer is generated from
  *                 a pseudo-random number generator.
 */


package Question6;
import javax.swing.*;
import java.util.concurrent.ThreadLocalRandom;


public class Main {

    public static void main(String[] args) {

        final int lowerBound = 1;
        final int upperBound = 1000;
        final int answer = getRandomAnswer(lowerBound, upperBound);

        // start a new guessing game with the answer between 1 and 1000 and zero attempts
        guessTheNumber(lowerBound, upperBound, answer, 0);
    }




    /******************************************************************************
     METHOD		    : guessTheNumber

     DESCRIPTION	:

     INPUT			: Type			: int
                    : Description	: The lower-bound of the guess range.

                    : Type			: int
                    : Description	: The upper-bound of the guess range.

                    : Type			: int
                    : Description	: The answer.

                    : Type			: int
                    : Description	: The number of the player's attempted guesses.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    static void guessTheNumber(int lowerBound, int upperBound, int answer, int attempts) {

        String input = JOptionPane.showInputDialog("Choose a number between " + lowerBound + " and " + upperBound);
        int guess = Integer.parseInt(input);

        // user's guess has to be within the bounds
        if(guess < lowerBound || guess > upperBound)
        {
            JOptionPane.showMessageDialog(null, "Invalid guess. Guess must be between " +
                    lowerBound + " and " + upperBound + ". Try again.");

            guessTheNumber(lowerBound, upperBound, answer, attempts);
        }

        // if the guess is incorrect, reset the boundaries based on the guess
        if(guess != answer)
        {
            if(guess > answer)
                upperBound = guess;
            else
                lowerBound = guess;

            // increase the attempts and try again with new range
            attempts++;
            guessTheNumber(lowerBound, upperBound, answer, attempts);
        }

        // if we got here, the user guessed correctly.
        JOptionPane.showMessageDialog(null,
                "You guessed it! The number was " + answer + "! .You took " + attempts + " attempts. Good Job!");

        // prompt the user to play again...
        while(true) {

            input = JOptionPane.showInputDialog("Play Again? Y/N").toUpperCase();

            if(input.equals("N"))
                return;

            else if(input.equals("Y")) {
                // start a new guessing game with new answer between 1 and 1000.
                answer = getRandomAnswer(1, 1000);
                guessTheNumber(1, 1000, answer, 0);
            }

            else
                JOptionPane.showMessageDialog(null,
                        "Not a valid option.","Invalid Option", JOptionPane.WARNING_MESSAGE);
        }
    }












    /******************************************************************************
     METHOD		    : getRandomAnswer

     DESCRIPTION	:

     INPUT			: Type			: int
                    : Description	:

                    : Type			: int
                    : Description	:

     OUTPUT			: Type 			: int
                    : Description	:
     ******************************************************************************/
    static int getRandomAnswer(int lowerBound, int upperBound){
        return ThreadLocalRandom.current().nextInt(lowerBound, upperBound);
    }
}
