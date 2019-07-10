/**
 * PROJECT:         Lab 6 - Question 5
 * FILE:            File.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   March 18, 2017
 * DESCRIPTION:
 */



package Question5;


public class File extends Document
{
    private String pathName;




    /******************************************************************************
     CONSTRUCTOR    : File

     DESCRIPTION	:

     INPUT			: Type			: String
                    : Description	:

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public File(String pathName)
    {
        this(pathName, "");
    }






    /******************************************************************************
     CONSTRUCTOR    : File

     DESCRIPTION	:

     INPUT			: Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

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

     DESCRIPTION	:

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	:
     ******************************************************************************/
    public String toString()
    {
        return super.getText();
    }
}
