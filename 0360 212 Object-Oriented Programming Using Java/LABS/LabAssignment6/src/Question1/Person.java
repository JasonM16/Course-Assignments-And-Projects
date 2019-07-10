/**
 * PROJECT          : Lab 6 - Question 1
 * FILE             : Person.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Implement a superclass "Person". A person has a name and a year of birth.
 *                    Write the class definitions, the constructors, and the methods "toString" for all classes.
 *                    You are free to add other methods as you see fit.
 */



package Question1;

public class Person
{
    private final String name;
    private final int yearOfBirth;


    /******************************************************************************
     CONSTRUCTOR	: Person

     DESCRIPTION	:

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    private Person()
    {
        name        = null;
        yearOfBirth = 1900;
    }





    /******************************************************************************
     CONSTRUCTOR	: Person

     DESCRIPTION	:

     INPUT			: Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Person(String name, int yearOfBirth)
    {
        this.name        = name;
        this.yearOfBirth = yearOfBirth;
    }





    /******************************************************************************
     METHOD		    : getName

     DESCRIPTION	: This method returns person's name.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: The person's name.
     ******************************************************************************/
    public String getName()
    {
        return name;
    }





    /******************************************************************************
     METHOD		    : getYearOfBirth

     DESCRIPTION	: This method returns person's year of birth.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: The person's year of birth.
     ******************************************************************************/
    public int getYearOfBirth()
    {
        return yearOfBirth;
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with person's details.
     ******************************************************************************/
    public String toString()
    {
        return "Person : " + name + "\tYear of Birth : " + yearOfBirth + "\n";
    }
}
