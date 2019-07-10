package Question3;

import javax.swing.JOptionPane;


public class Test {
  
	public static void main( String args[] )
	{
		String firstName 	= JOptionPane.showInputDialog( "Enter your First name" );
		String lastName  	= JOptionPane.showInputDialog( "Enter your Last name" );
		String colorString 	= JOptionPane.showInputDialog( "What color is your car? " );
		String milesString	= JOptionPane.showInputDialog( "how many miles have you" +
		  " driven in your car? " );
		     
		double miles 		= Double.parseDouble( milesString );
		Miles mile 			= new Miles(miles);
		Color color 		= new Color(colorString);
		Person person 		= new Person( firstName , lastName );
		    
		String output = person.getFirstName()+ " " + person.getLastName() +
		   " drove his/her " + color.getColor() +  " car " +
		   " for " + mile.toString() + " Question3.Miles";
		     
		JOptionPane.showMessageDialog( null, output, "Testing class Race",
		   JOptionPane.INFORMATION_MESSAGE );
		     
		System.exit( 0 );

	}
}