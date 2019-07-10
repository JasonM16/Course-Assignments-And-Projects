/**
 * PROJECT:     Lab 3 - Question 1
 * FILE:        Date_Test.java
 * AUTHOR:      Jason Choquette -104337378
 * DATE:        February 2, 2017
 * DESCRIPTION: This is a testing class for the Date object. Its main application is to test whether one date is less
 *              than another date. It also prints the results of the test(s) to the console.
 */


package Question1;
public class Date_Test {


    /******************************************************************************
     METHOD		    : Test

     DESCRIPTION	: This method runs tests for a test date against an array of dates
                      and then calls a method to print the results.

     INPUT			: Type			: Date
                    : Description	: A date to be tested.

                     : Type			: Date[]
                     : Description	: An array of dates to run tests against.

                     : Type			: int
                     : Description	: The current test run.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void Test(Date date, Date[] testDates, int testId) {

        System.out.println("Test " + testId + ": \n");
        for (Date d: testDates)
            PrintResults(date, d);

        System.out.println("");
    }




    /******************************************************************************
     METHOD		    : PrintResults

     DESCRIPTION	: This method prints the results of the test(s).

     INPUT			: Type			: Date
                    : Description	: The first Date.

                    : Type			: Date
                    : Description	: The second Date.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void PrintResults(Date date, Date d) {

        System.out.print(date);
        System.out.print(" is less than ");
        System.out.print(d);
        System.out.println("? : " + date.isLessThan(d));
    }
}
