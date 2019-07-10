/**
 * PROJECT          : Lab 6 - Question 5
 * FILE             : Document.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Define a class named Document that contains an instance variable of type String named text that
 *                    stores any textual content for the document. Create a method named toString that returns the text
 *                    field and also include a method to set this value.
 */


package Question5;


public class Document
{
    private String text;


    /******************************************************************************
     CONSTRUCTOR    : Document

     DESCRIPTION	: Document constructor.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Document()
    {
        this("");
    }






    /******************************************************************************
     CONSTRUCTOR    : Document

     DESCRIPTION	: Document constructor.

     INPUT			: Type			: String
                    : Description	: The document's text.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Document(String text)
    {
        this.text = text;
    }






    /******************************************************************************
     METHOD		    : getText

     DESCRIPTION	: This method gets the text of a document.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: The document's text.
     ******************************************************************************/
    public String getText()
    {
        return text;
    }







    /******************************************************************************
     METHOD		    : setText

     DESCRIPTION	: This method sets the text of a document.

     INPUT			: Type			: String
                    : Description	: The text of the document.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void setText(String text)
    {
        this.text = text;
    }





    /******************************************************************************
     METHOD		    : Contains

     DESCRIPTION	: This method tests if a keyword is in a string of text.

     INPUT			: Type			: Document
                    : Description	:

                    : Type			: String
                    : Description	:

     OUTPUT			: Type 			: boolean
                    : Description	: True if word is in the text. False, otherwise.
     ******************************************************************************/
    public static boolean Contains(Document document, String keyword)
    {
        return document.toString().indexOf(keyword, 0) >= 0;
    }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with document's text.
     ******************************************************************************/
    public String toString()
    {
        return "\nDocument text: \n" + text + "\n";
    }

}
