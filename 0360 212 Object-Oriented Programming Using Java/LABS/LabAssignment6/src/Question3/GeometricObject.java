/**
 * PROJECT          : Lab 6 - Question 3
 * FILE             : GeometricObject.java
 * AUTHOR           : Dr. Dan Wu, Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * DESCRIPTION      :
 */


package Question3;

import java.util.Date;


public class GeometricObject
{
    private Color color;
    private boolean filled;
    private Date dateCreated;


    public GeometricObject() { this(Color.White); }





    public GeometricObject(Color color) // don't want null as color
    {
        this.color  = color;
        dateCreated = new Date();
    }




    public Color getColor() { return color; }


    public void setColor(Color color) { this.color = color; }


    public boolean isFilled() { return filled; }


    public void setFilled(boolean filled) { this.filled = filled; }


    public Date getDateCreated() { return dateCreated; }


    public String toString() { return "created on " + dateCreated + "\ncolor: " + color + " and filled: " + filled; }


    public enum Color
    {
        Red,
        Orange,
        Blue,
        Yellow,
        Green,
        Black,
        White,
        Purple,
        Brown,
        Pink,
        Silver
    }
}

