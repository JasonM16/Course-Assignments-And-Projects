/**
 * PROJECT:     Lab 3 - Question 1
 * FILE:        Date.java
 * AUTHOR:      Jason Choquette - 104337378
 * DATE:        February 2, 2017
 * DESCRIPTION: This class represents a date object. It has one method that compares dates to determine
 *              if one date is less than another.
 */

package Question1;

public class Date {

    // member variables
    private final int day, month, year;
    private int fullYear;

    // array to hold month names. Used for output in the toString() method.
    // Note index zero is blank...
    String[] Months = new String[] { "",
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November",
            "December" };





    /******************************************************************************
     CONSTRUCTOR    : Date

     DESCRIPTION	: This constructor initializes the day month and year of a new
                      date object .

     INPUT			: Type			: int
                    : Description	: Numeric day of the month.

                    : Type			: int
                    : Description	: Numeric month of the year.

                     : Type			: int
                     : Description	: Last two digits of the year.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Date(int d, int m, int y) {

        day      = d;
        month    = m;
        year     = y;
        fullYear = y;
        setCentury(y);
    }





    /******************************************************************************
     METHOD		    : setCentury

     DESCRIPTION	: This method sets the year to either the 20th or 21st century.
                      This is required to correctly compare two dates.

     INPUT			: Type			: int
                    : Description	: Last two digits of the year.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void setCentury(int y)
    {
        if(y >= 50)
            fullYear += 1900;
        else
            fullYear += 2000;
    }





    /******************************************************************************
     METHOD		    : lessThan

     DESCRIPTION	: This method compares two dates to determine if one date (the
                      instance variable) is less than another date (test variable).

     INPUT			: Type			: Date
                    : Description	: The full date.

     OUTPUT			: Type 			: boolean
                    : Description	: Returns true if the instance date is less
                                      than the argument date.
     ******************************************************************************/
    public boolean isLessThan (Date date)
    {
        if (this.fullYear < date.fullYear)
            return true;
        else if(this.fullYear == date.fullYear && this.month < date.month)
            return true;
        else if(this.fullYear == date.fullYear && this.month == date.month && this.day < date.day)
            return true;
        else
            return false;
    }





    /******************************************************************************
     GETTER		    : getDay

     DESCRIPTION	: Returns the day of the month.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: Returns the day of the month.
     ******************************************************************************/
     public int getDay() {
        return day;
    }





    /******************************************************************************
     GETTER		    : getMonth

     DESCRIPTION	: Returns the month of the year.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: Returns the month of the year.
     ******************************************************************************/
     public int getMonth() {
        return month;
    }





    /******************************************************************************
     GETTER		    : getYear

     DESCRIPTION	: Returns the year.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: Returns the year.
     ******************************************************************************/
     public int getYear() {
        return year;
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides the toString() method for the date object.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns formatted date string.
     ******************************************************************************/
    public String toString()
    {
        String date = Months[month] + " " + day + ", " + "'"; // last 2 digits of the year
        String y = String.format("%02d", year);
        date += y;
        return date;
    }
}
