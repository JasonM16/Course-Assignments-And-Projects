/**
 * PROJECT          : Lab 6 - Question 2
 * FILE             : Manager.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 18, 2017
 * REQUIREMENTS     : Make a class "Manger" that inherits from "Employee".
 *                    Add an instance field, named "department", of type String.
 *                    Supply a method "toString" that prints the manger's name, department, and salary.
 */


package Question2;


public class Manager extends Employee
{
    private final Department department;


    /******************************************************************************
     CONSTRUCTOR    : Manager

     DESCRIPTION	: Manager constructor.

     INPUT			: Type			: String
                    : Description	: The manager's name.

                    : Type			: double
                    : Description	: The manager's salary.

                    : Type			: Department
                    : Description	: The manager's department.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Manager(String name, double salary, Department department)
    {
        super(name, salary);
        this.department = department;
    }





    /******************************************************************************
     METHOD		    : getDepartment

     DESCRIPTION	: Returns the manager's department

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: Department
                    : Description	: The manager's department
     ******************************************************************************/
    public Department getDepartment()
    {
        return department;
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with Manager's details.
     ******************************************************************************/
    public String toString()
    {
        return "Manager : " + getName() + "\ngetDepartment : " + department + "\nSalary : " + getSalaryString() + "\n";
    }




    /******************************************************************************
     ENUM		    : Department

     DESCRIPTION	: Represents organization's departments

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public enum Department
    {
        Accounting,
        Sales,
        HR,
        IT,
        Finance,
        Operations
    }






}
