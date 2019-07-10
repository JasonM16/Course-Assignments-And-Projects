/**
 * PROJECT          : Lab 6 - Question 2
 * FILE             : Main.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Supply a test program that tests these classes and methods.
 */


package Question2;


public class Main
{
    public static void main (String[] args)
    {
        Employee e1 = new Employee("Jason Choquette", 118_000);
        Executive ex1 = new Executive("Jason Choquette", 230_500, Manager.Department.Finance);
        Manager m1 = new Manager("Some Person", 20000, Manager.Department.Sales);

        System.out.println(e1);
        System.out.println(ex1);
        System.out.println(m1);
    }
}
