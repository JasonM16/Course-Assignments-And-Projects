/**
 * PROJECT          : Lab 6 - Question 3
 * FILE             : Triangle.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Design a class named Triangle that extends the GeometricObject class we discussed in class.
 *
 *                  This class contains:
 *                  - Three double data fields named side1, side2, and side3 with default values 1.0 to denote
 *                    three sides of the triangle.
 *                  - A no-arg constructor that creates a default triangle.
 *                  - A constructor that creates a triangle with specified side1, side2, and side3.
 *                  - The accessor methods for all three data fields.
 *                  - A method named getArea() that returns the area of this triangle. (google how to compute
 *                    area of a triangle given three sides)
 *                  - A method named getPerimeter() that returns the perimeter of this triangle.
 *                  - A method named toString() that returns a string description for the triangle.
 */


package Question3;


public class Triangle extends GeometricObject
{
    private final double side1;
    private final double side2;
    private final double side3;





    /******************************************************************************
     CONSTRUCTOR    : Triangle

     DESCRIPTION	: Triangle default constructor.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Triangle()
    {
       super();
       side1 = side2 = side3 = 1.0d;
    }





    /******************************************************************************
     CONSTRUCTOR    : Triangle

     DESCRIPTION	: Triangle constructor.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Triangle(Color color) throws Exception
    {
        this(1.0, 1.0, 1.0, color);
    }





    /******************************************************************************
     CONSTRUCTOR    : Triangle

     DESCRIPTION	: Triangle constructor.

     INPUT			: Type			: double
                    : Description	: side length 1

                    : Type			: double
                    : Description	: side length 2

                    : Type			: double
                    : Description	: side length 3

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Triangle(double side1, double side2, double side3) throws Exception
    {
        this(side1, side2, side3, Color.White);
    }





    /******************************************************************************
     CONSTRUCTOR    : Triangle

     DESCRIPTION	: Triangle constructor.

     INPUT			: Type			: double
                    : Description	: side length 1

                    : Type			: double
                    : Description	: side length 2

                    : Type			: double
                    : Description	: side length 3

                    : Type			: String
                    : Description	: The triangle's color.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Triangle(double a, double b, double c, Color color) throws Exception
    {
        /* Triangle Inequality Theorem */
        if((a+b) <= c || (a+c) <= b || (b+c) <= a)
            throw new Exception("\n\n****  Not a triangle  ****\n" +
                    "The sum of two sides of a triangle must be greater than the third side.\n");

        this.side1 = a;
        this.side2 = b;
        this.side3 = c;
        setColor(color);
    }





    /******************************************************************************
     METHOD		    : getArea

     DESCRIPTION	: This method calculates the area of a triangle.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: double
                    : Description	: The area of the triangle.
     ******************************************************************************/
    /*Heron's formula */
    // https://www.mathsisfun.com/geometry/herons-formula.html
    public double getArea()
    {
        double s = 0.5 * getPerimeter();
        double area = Math.sqrt(s * ((s - side1) * (s - side2) * (s - side3)));
        return area;
    }





    /******************************************************************************
     METHOD		    : getPerimeter

     DESCRIPTION	: This method calculates the perimeter of a triangle.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: double
                    : Description	: The perimeter of the triangle.
     ******************************************************************************/
    public double getPerimeter()
    {
        return side1 + side2 + side3;
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with Triangle's details.
     ******************************************************************************/
    public String toString()
    {
        return getColor() + " Triangle: \n" +
                "\nSide 1: " + side1 +
                "\nSide 2: " + side2 +
                "\nSide 3: " + side3 +
                "\nArea: "   + getArea() +
                "\nPerimeter: " + getPerimeter() +
                "\n";
    }
}
