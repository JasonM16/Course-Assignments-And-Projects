/**
 * PROJECT          : Lab 6 - Question 5
 * FILE             : File.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 20, 2017
 * REQUIREMENTS     : Define a class for File that is derived from Document and includes a instance variable for the
 *                    pathname. The textual contents of the file should be stored in the inherited variable text.
 *                    Redefine the toString method to concatenate all text fields.
 */


package Question5;


public class File extends Document
{
    private String pathName;


    /******************************************************************************
     CONSTRUCTOR    : File

     DESCRIPTION	: File constructor.

     INPUT			: Type			: String
                    : Description	: The location/path of the file.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public File(String pathName)
    {
        this(pathName, "");
    }






    /******************************************************************************
     CONSTRUCTOR    : File

     DESCRIPTION	: File constructor

     INPUT			: Type			: String
                    : Description	: The location/path of the file.

                    : Type			: String
                    : Description	: The text contained in the file.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public File (String pathName, String fileText)
    {
        super(fileText);
        this.pathName = pathName;
    }







    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: his method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with file's details.
     ******************************************************************************/
    public String toString()
    {
        return "\nFile location: " + pathName + "\nFile contents: " + super.getText() + "\n";
    }
}
