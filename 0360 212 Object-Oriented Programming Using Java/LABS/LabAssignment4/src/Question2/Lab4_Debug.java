package Question2;

// Debugging the following program Problem
// be sure to comment your changes
// what does this program do?

//remove unused import
import javax.swing.*;




// this program obtains information from the user regarding student's and their grades.
// Once completed, the program shows the maximum, minimum and average of all the student
// grades that were entered
public class Lab4_Debug
{
    public static void main(String str[])
    {
	    String students = JOptionPane.showInputDialog(
        	 "Please enter the number of students you wish to average" ); 

	    // rename to paresInt
        // removed redundant variable
        int NumOfStudents = Integer.parseInt( students );
        int counter = 1;

        double total = 0, previousNumber = 0, newMaximum = 0, newMinimum = 0;
        
        while ( NumOfStudents != 0 )
        {
            String si = JOptionPane.showInputDialog( "Please enter a grade" );
            double givenNum = Double.parseDouble( si );
            total = total + givenNum;

            if ( counter == 1 )
            {
                previousNumber = givenNum;
                newMinimum = givenNum;
            }

            if ( newMaximum < givenNum )
                newMaximum = maximum( previousNumber, givenNum );

            if ( newMinimum > givenNum )
                newMinimum = minimum( previousNumber, givenNum );

            NumOfStudents--;
            counter++;
            previousNumber = givenNum;
        }

        // reset the number of students, so we don't divide by zero
        NumOfStudents = Integer.parseInt( students );


	    JOptionPane.showMessageDialog(null,  "The maximum: " + newMaximum +
	       "\nThe Average: " + average( total, NumOfStudents ) + " \nThe minimum: " + newMinimum);
		  
		System.exit(0);
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    // Need to set all methods as static in order to be called from the static main method
    ///////////////////////////////////////////////////////////////////////////////////////


    // added type double to parameter y
    public static double average( double x, double y )// remove semicolon
    {
      return x / y;
    }

    // added return statement
    public static double maximum( double x, double y )
    {
      return Math.max( x, y );
    }

    // Used fully qualified method name for min
    // change method signature for both parameters to double
    public static double minimum( double x, double y )
    {
      return Math.min( x, (float)y ); // cast y as float to ensure result is not 0.0
    }
}

