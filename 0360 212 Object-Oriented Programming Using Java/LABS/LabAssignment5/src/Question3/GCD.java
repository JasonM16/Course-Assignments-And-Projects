/**
 * PROJECT          : Lab 5 - Question 3
 * FILE             : GCD.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 12, 2017
 * REQUIREMENTS     : The greatest common divisor of integers x and y is the largest integer that evenly divides
 *                    into both x and y.
 *
 *                    Write a recursive method gcd that returns the greatest common divisor of x and y.
 *
 *                    The gcd of x and y is defined recursively as follows:
 *                    - If y is equal to 0, then gcd( x, y ) is x;
 *                    - otherwise, gcd( x, y ) is gcd(y, x%y), where % is the remainder operator.
 */


package Question3;


public class GCD
{
    public static void main(String[] args)
    {
        System.out.println(gcd(210, 25));
    }



    /******************************************************************************
     METHOD		    : gcd

     DESCRIPTION	: This is a recursive method to calculate the greatest common
                      denominator (gcd) of two integers.

     INPUT			: Type			: int
                    : Description	: The first integer.

                    : Type			: int
                    : Description	: The second integer.

     OUTPUT			: Type 			: int
                    : Description	: The gcd.
     ******************************************************************************/
    public static int gcd(int x, int y)
    {
        if(y == 0) return x;
        return gcd(y, x % y);
    }
}
