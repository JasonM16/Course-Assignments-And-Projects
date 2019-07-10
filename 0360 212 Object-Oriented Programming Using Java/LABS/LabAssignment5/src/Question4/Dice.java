/**
 * PROJECT          : Lab 5 - Question 4
 * FILE             : Dice.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 12, 2017
 * REQUIREMENTS     : Write an application to simulate the rolling of two dice.
 *
 *                  The application should use an object of class Random once to roll the first die and again to roll
 *                  the second die. The sum of the two values should then be calculated.
 *
 *                  Each die can show an integer value from 1 to 6, so the sum of the values will vary from 2 to 12,
 *                  with 7 being the most frequent sum, and 2 and 12 the least frequent.
 *
 *                  Your application should roll the dice 36,000,000 times.
 *
 *                  Use a one-dimensional array to tally the number of times each possible sum appears.
 *                  Display the results in tabular format.
 */


package Question4;

import java.util.Random;

public class Dice
{
    public static void main(String[] args)
    {
       int[] result = generateArrayOfRolls();

        for (int i = 2; i <= 12; i++)
        {
            System.out.print("\n" + i + ":\t" + result[i] + "\t\t");
            System.out.printf("%.3f%%", result[i]/((float)36_000_000) * 100);
        }

        System.out.println();
    }





    /******************************************************************************
     METHOD		    : generateArrayOfRolls

     DESCRIPTION	: This method generates an array of 36 million simultated dice
                      tosses (roles).

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int[]
                    : Description	: An array of randomly generated dice rolls.
     ******************************************************************************/
    private static int[] generateArrayOfRolls()
    {
        int[] rolls = new int[12+1];
        int sum;

        for(int i = 0; i <= 36_000_000; i++)
        {
            sum = calculateSum();
            rolls[sum] += 1;
        }

        return rolls;
    }





    /******************************************************************************
     METHOD		    : calculateSum

     DESCRIPTION	: This method calculates the sum of a rolling of two die's.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: The sum of the dice rolls.
     ******************************************************************************/
    public static int calculateSum()
    {
        return randomRoll() + randomRoll();
    }





    /******************************************************************************
     METHOD		    : randomRoll

     DESCRIPTION	: This method generates a rond integer between 1 and six to
                      simulate a rolling of a single die.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: The random integer between 1 and 6.
     ******************************************************************************/
    public static int randomRoll()
    {
        int upperBound = 7;
        int lowerBound = 1;
        return new Random().nextInt(upperBound - lowerBound) + lowerBound;
    }
}
