/***************************************************  NOTICE  **********************************************************
 * Portions of solution are based on an open-source license (GNU) implementation of an arbitrary-digit integer type.
 * The code has been altered to meet assignment requirements.
 *
 * Licenses for each class are provided at the bottom of each source file.
 *
 * Although the code is not entirely my own, I wanted to take the opportunity to learn how primitive data types and
 * operations are implemented in a modern language; and modify production code to learn the correct way to implement the
 * operations and data structures.
 *
 * I understand if a zero is given for this question since it is not completely my own code.
/***********************************************************************************************************************

/**
 * PROJECT          : Lab 5 - Question 5
 * FILE             : Main.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 12, 2017
 * REQUIREMENTS     : This is a testing application for the HugeInteger class.
 */


package Question5;


public class Main
{
    public static void main(String[] args)
    {
        HugeInteger a = new HugeInteger("92345678910113212139234567891011321213");
        //int debs = 92345678910113212139234567891011321213;
        HugeInteger b = new HugeInteger("25");
        HugeInteger c = new HugeInteger("256875");
        HugeInteger d = new HugeInteger("-3215");
        HugeInteger e = new HugeInteger("756544545");
        HugeInteger f = new HugeInteger("-92345678910113212139234567891011321213");
        HugeInteger g = new HugeInteger("7");
        HugeInteger j = new HugeInteger("7");

        int dtg = 765454 - 656535;
        System.out.println(a.add(f));
        System.out.println(d.subtract(c));
        System.out.println(g.subtract(b));
        System.out.println(d.add(c));

        System.out.println();

        System.out.println(j.isEqualTo(e));                 // true
        System.out.println(j.isLessThan(e));                // false
        System.out.println(j.isNotEqualTo(e));              // false
        System.out.println(j.isGreaterThan(e));             // false
        System.out.println(j.isGreaterThanOrEqualTo(e));    // true
        System.out.println(j.isLessThanOrEqualTo(e));       // true

        System.out.println();

        System.out.println(j.isEqualTo(d));                 // false
        System.out.println(j.isLessThan(d));                // true
        System.out.println(j.isNotEqualTo(b));              // true
        System.out.println(j.isGreaterThan(b));             // false
        System.out.println(j.isGreaterThanOrEqualTo(f));    // false
        System.out.println(j.isLessThanOrEqualTo(f));       // true
        System.out.println(d.isZero());                     // false
    }
}