/**
 * PROJECT          : Lab 6 - Question 1
 * FILE             : Student.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Make two subclasses, "Student" and "Instructor", that inherit from "Person". A student has a major.
 *                    Write the class definitions, the constructors, and the methods "toString" for all classes.
 *                    You are free to add other methods as you see fit.
 */

package Question1;

public class Student extends Person
{
    private Major major;
    //Hash map is O(1) lookup so is really efficient way to store string representations of majors.
    private static java.util.HashMap<Major, String> majors = new java.util.HashMap<>();
    static
    {
        majors.put(Major.Architecture,              "Architecture");
        majors.put(Major.Business,                  "Business");
        majors.put(Major.Chemistry,                 "Chemistry");
        majors.put(Major.ComputerScience,           "Computer Science");
        majors.put(Major.MechanicalEngineering,     "Mechanical Engineering");
        majors.put(Major.History,                   "History");
        majors.put(Major.PoliticalScience,          "Political Science");
        majors.put(Major.Physics,                   "Physics");
        majors.put(Major.ElectricalEngineering,     "Electrical Engineering");
        majors.put(Major.Undeclared,                "Undeclared");
    }





    /******************************************************************************
     CONSTRUCTOR    : Student

     DESCRIPTION	: Student constructor.

     INPUT			: Type			: String
                    : Description	: The student's name.

                    : Type			: int
                    : Description	: The student's year of birth.

                    : Type			: Major
                    : Description	: The student' major.s

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Student(String name, int yearOfBirth, Major major)
    {
        super(name, yearOfBirth);
        this.major = major;
    }






    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with student details.
     ******************************************************************************/
     public String toString()
     {
         return "Student : " + getName() + "\tMajoring in : " + majors.get(major) + "\n";
     }





    /******************************************************************************
     ENUM		    : Major

     DESCRIPTION	: Represents the majors a student can enroll in.

     INPUT			: Type			: N/A
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public enum Major
    {
        Architecture,
        Business,
        MechanicalEngineering,
        Physics,
        Chemistry,
        ComputerScience,
        PoliticalScience,
        History,
        ElectricalEngineering,
        Undeclared
    }
}
