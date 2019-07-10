/**
 * PROJECT          : Lab 6 - Question 5
 * FILE             : Email.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Define a class for Email that is derived from Document and includes instance variables for the
 *                    sender, recipient, and title of an email message. Implement appropriate accessor and mutator methods.
 *                    The body of the email message should be stored in the inherited variable text. Redefine the toString
 *                    method to concatenate all text fields.
 */


package Question5;


public class Email extends Document
{
    private String sender;
    private String receiver;
    private String title;





    /******************************************************************************
     CONSTRUCTOR    : Email

     DESCRIPTION	: Email constructor

     INPUT			: Type			: String
                    : Description	: The email's author.

                    : Type			: String
                    : Description	: The email's recipient(s)

                    : Type			: String
                    : Description	: Title of the email.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Email(String sender, String receiver, String title)
    {
        this(sender, receiver, receiver, title);
    }







    /******************************************************************************
     CONSTRUCTOR    : Email

     DESCRIPTION	: Email constructor

     INPUT			: Type			: String
                    : Description	: The email's author.

                    : Type			: String
                    : Description	: The email's recipient(s)

                    : Type			: String
                    : Description	: Title of the email.

                    : Type			: String
                    : Description	: The body of the email.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Email(String sender, String receiver, String title, String text)
    {
        super(text);
        this.sender = sender;
        this.receiver = receiver;
        this.title = title;
    }






    /******************************************************************************
     METHOD		    : createEmailMessage

     DESCRIPTION	: This method sets the body of an email.

     INPUT			: Type			: String
                    : Description	: The body of an email.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void createEmailMessage(String emailMessage)
    {
        super.setText(emailMessage);
    }







    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method overrides Java's built-in toString method.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns a string with email's details.
     ******************************************************************************/
    public String toString()
    {
        return "\nEmail:\nSender: " + sender + "\nReceiver: " + receiver + "\nTitle: " + title + "\nMessage body: " + super.getText() + "\n";
    }


}
