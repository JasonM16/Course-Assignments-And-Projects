/**
 * PROJECT          : Lab 6 - Question 3
 * FILE             : Main.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Write a test program to test the various date fields and methods.
 */


package Question3;


public class Main
{
    public static void main(String[] args) throws Exception
    {
        Triangle t1 = new Triangle(3, 4, 5);
        Triangle t2 = new Triangle();
        Triangle t3 = new Triangle(GeometricObject.Color.Green);
        Triangle t4 = new Triangle(8, 5, 7, GeometricObject.Color.Silver);

        System.out.println(t1);
        System.out.println(t2);
        t2.setColor(GeometricObject.Color.Green);
        System.out.println(t3);
        System.out.println(t4);
    }
}
