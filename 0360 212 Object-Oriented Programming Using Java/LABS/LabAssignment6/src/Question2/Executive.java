/**
 * PROJECT          : Lab 6 - Question 2
 * FILE             : Executive.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 18, 2017
 * REQUIREMENTS     : Make a class "Executive" that inherits from "Manager".
 *                    Supply appropriate "toString" methods for all classes.
 *                    You are free to add other methods as you see fit.
 */



package Question2;

public class Executive extends Manager
{



    /******************************************************************************
     CONSTRUCTOR    : Executive

     DESCRIPTION	: Executive constructor.

     INPUT			: Type			: String
                    : Description	: The executive's name.

                    : Type			: double
                    : Description	: The executive's salary.

                    : Type			: Department
                    : Description	: The executive's department.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Executive(String name, double salary, Department department)
    {
        super(name, salary, department);
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overloads Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with executive's details.
     ******************************************************************************/
    public String toString()
    {
        return "Executive : " + getName() + "\ngetDepartment : " + getDepartment() + "\n";
    }
}
