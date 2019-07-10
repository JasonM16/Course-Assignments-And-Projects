/**
 * PROJECT          : Lab 6 - Question 1
 * FILE             : Main.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 18, 2017
 * REQUIREMENTS     : Supply a test program that tests these classes and methods.
 */


package Question1;


public class Main
{
    public static void main(String[] args)
    {
        Person p1 = new Person("Jason Choquette", 1954);
        Student s1 = new Student("Jason Choquette", 2011, Student.Major.ComputerScience);
        Instructor i1 = new Instructor("Alan Turing", 1936, 1_000_000d);

        System.out.println(p1);
        System.out.println(s1);
        System.out.println(i1);
    }
}
