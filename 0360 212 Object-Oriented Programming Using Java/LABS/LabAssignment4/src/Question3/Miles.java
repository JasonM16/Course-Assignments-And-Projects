package Question3;

import java.text.DecimalFormat;


public class Miles  {

	// make miles mutable
	private double miles;
	   
	public Miles()
	{
	   this( 0.0 );
	}

	public Miles(double miles)
	{
		setMile( miles );
	}
	
	public void setMile( double m )
	{
	   miles = ( ( m >= 0.0 && m <= 200000 ) ? m : 0 );
	}


	// typo in DecimalFormat declaration
	// overload toString method
	public String toString()
	{
	   DecimalFormat formatMile = new DecimalFormat( "0" );
	   return formatMile.format( miles );  
	}
}