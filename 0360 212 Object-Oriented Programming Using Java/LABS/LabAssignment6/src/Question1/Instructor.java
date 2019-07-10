/**
 * PROJECT          : Lab 6 - Question 1
 * FILE             : Instructor.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Make two subclasses, "Student" and "Instructor", that inherit from "Person".
 *                    An instructor has a salary.
 *                    Write the class definitions, the constructors, and the methods "toString" for all classes.
 *                    You are free to add other methods as you see fit.
 */

package Question1;

import java.text.NumberFormat;

public class Instructor extends Person
{
    private final double salary;



    /******************************************************************************
     CONSTRUCTOR    : Instructor

     DESCRIPTION	: Instructor constructor

     INPUT			: Type			: String
                    : Description	: Instructor's name.

                    : Type			: int
                    : Description	: Instructor's year of birth.

                    : Type			: double
                    : Description	: Instructor's salary

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Instructor(String name, int yearOfBirth, double salary)
    {
        super(name, yearOfBirth);
        this.salary = salary;
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with instructor's details.
     ******************************************************************************/
    public String toString()
    {
        NumberFormat formatter = NumberFormat.getCurrencyInstance();
        return "Instructor : " + getName() + "\tSalary : " + formatter.format(salary) + "\n";
    }
}
