/**
 * PROJECT:     Lab 3 - Question 1
 * FILE:        Main.java
 * AUTHOR:      Jason Choquette - 104337378
 * DATE:        February 2, 2017
 * DESCRIPTION: This is the driver for the Date and Date_Test classes. It simply creates date and date_test objects
 *              and runs the tests.
 */

package Question1;

public class Main {

    public static void main(String[] args) {

        // create an array of dates
        Date[] dates = new Date[]
        {
             new Date(26, 05, 99),
             new Date( 8, 06, 94),
             new Date(15, 03, 00),
             new Date(26, 05, 99),
        };

        // create some date test data
        Date d4 = new Date(25, 05, 99);
        Date d5 = new Date(25, 01, 00);
        Date d6 = new Date(26, 05, 99);

        // instantiate new tests
        Date_Test t1 = new Date_Test();
        Date_Test t2 = new Date_Test();
        Date_Test t3 = new Date_Test();

        // run tests against dates in array
        t1.Test(d4, dates, 1);
        t2.Test(d5, dates, 2);
        t3.Test(d6, dates, 3);
    }
}
