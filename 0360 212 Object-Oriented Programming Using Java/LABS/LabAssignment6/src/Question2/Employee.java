/**
 * PROJECT          : Lab 6 - Question 2
 * FILE             : Employee.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Make a class "Employee" with a name and salary.
 */



package Question2;

import java.text.NumberFormat;

public class Employee
{
     private final String name;
     private final double salary;





    /******************************************************************************
     CONSTRUCTOR    : Employee

     DESCRIPTION	: Employee default constructor.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
     private Employee()
     {
         name = null;
         salary = 0.0d;
     }





    /******************************************************************************
     CONSTRUCTOR    : Employee

     DESCRIPTION	: Employee constructor

     INPUT			: Type			: String
                    : Description	: The employees name.

                    : Type			: double
                    : Description	: The employee's salary.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
     public Employee(String name, double salary)
     {
         this.name = name;
         this.salary = salary;
     }





    /******************************************************************************
     METHOD		    : getName

     DESCRIPTION	: This method returns the employees name.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: The employees name.
     ******************************************************************************/
     public String getName()
     {
         return name;
     }







    /******************************************************************************
     METHOD		    : getSalary

     DESCRIPTION	: This method returns the numeric value of an employees salary.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: double
                    : Description	: The employees salary.
     ******************************************************************************/
     public double getSalary() { return salary; }






    /******************************************************************************
     METHOD		    : getSalaryString

     DESCRIPTION	: This method returns the employees salary as a string.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: The employees salary.
     ******************************************************************************/
     public String getSalaryString()
     {
         NumberFormat formatter = NumberFormat.getCurrencyInstance();
         return formatter.format(salary);
     }




    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overloads Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with employees details.
     ******************************************************************************/
     public String toString()
     {
         return "Employee : " + name + "\nSalary : " + getSalaryString() + "\n";
     }
}
