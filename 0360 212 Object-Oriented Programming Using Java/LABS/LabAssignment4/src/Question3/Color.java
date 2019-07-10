package Question3;


public class Color {

	private String color;

	// Constructor signatures have no return types by definition
	// to set a default color, we have two options:

	// 1. Create a constructor to receive the color as a parameter
	public Color(String color)
	{
		this.color = color;
	}

	// 2. Use a default Constructor and Constructor chaining
	public Color()
	{
		this("");
	}

	// appears to be a setter to set a default color of black??
	// rename to state the purpose of the function.
	// remove return statement.
	public void setColorBlack()
	{
	   this.color = "black";
	}

	// setter for property: color.
	// remove return statement.
	public void setColor(String color)
	{
		this.color = color;
	}

	// add a getter method...
	public String getColor()
	{
		return color;
	}

	// rename to allow for overloading and direct printing
	public String toString()
	{
	   return color;
	}
}
