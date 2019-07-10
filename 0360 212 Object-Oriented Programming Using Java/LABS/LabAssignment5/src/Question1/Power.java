/**
 * PROJECT          : Lab 5 - Question 1
 * FILE             : Power.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 11, 2017
 * REQUIREMENTS     : Write a Java program that implements a recursive method power( base, exponent ) that,
 *                    when called, returns base^exponent.
 */


package Question1;


public class Power
{

    public static void main(String[] args)
    {
        int b = 2;
        int e = 4;
        System.out.println(power(b, e));
    }



    /******************************************************************************
     METHOD		    : power

     DESCRIPTION	: This is a recursive method that calculates the value of a
                      power (i.e., base raised to an exponent).

     INPUT			: Type			: int
                    : Description	: The base.

                    : Type			: int
                    : Description	: The exponent.

     OUTPUT			: Type 			: int
                    : Description	: The resulting power.
     ******************************************************************************/
    private static int power(int base, int exponent)
    {
        assert (exponent >= 1);
        if (exponent == 1) return base;
        else base *= power(base, exponent - 1);

        return base;
    }
}
