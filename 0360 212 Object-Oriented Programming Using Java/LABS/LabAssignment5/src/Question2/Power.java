/**
 * PROJECT          : Lab 5 - Question 2
 * FILE             : Power.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 12, 2017
 * REQUIREMENTS     : Continue on Question 1, when computing base^exponent.
 *
 *                    If exponent is even, then: base^exponent = (base^(exponent/2))^2.
 *                    Improve your program in Question 1 by making use of the fact above.
 */


package Question2;


public class Power
{
    public static void main(String[] args)
    {
        int b = 2;
        int e = 4;
        System.out.println(betterPower(b, e));
    }


    /******************************************************************************
     METHOD		    : betterPower

     DESCRIPTION	: This is a recursive method that calculates the value of a
                      power (i.e., base raised to an exponent).

     INPUT			: Type			: int
                    : Description	: base

                    : Type			: int
                    : Description	: exponent

     OUTPUT			: Type 			: int
                    : Description	: The resulting power.
     ******************************************************************************/
    public static int betterPower(int base, int exponent)
    {
        assert (exponent >= 0);
        if (exponent == 0) return 1;
        if (exponent % 2 == 1)
        {
            int y = betterPower(base, (exponent - 1) / 2);
            return base * y * y;
        }
        else
        {
            int y = betterPower(base, exponent / 2);
            return y * y;
        }
    }
}
