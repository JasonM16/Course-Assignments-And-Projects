package Question3;

public class Person  {

	private String firstName;
	private String lastName; 

	// was not setting instance variables
	// names would always be null....
	public Person( String firstName, String lastName )
	{
	   this.lastName = lastName;
	   this.firstName = firstName;
	}
	
	public String getFirstName()
	{
	   return firstName; 
	}
	
	public String getLastName()
	{
	   return lastName;        
	}
}