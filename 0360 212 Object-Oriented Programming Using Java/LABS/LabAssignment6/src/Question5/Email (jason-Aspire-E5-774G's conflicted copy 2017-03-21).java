/**
 * PROJECT:         Lab 6 - Question 5
 * FILE:            Email.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   March 18, 2017
 * DESCRIPTION:
 */



package Question5;


public class Email extends Document
{
    private String sender;
    private String receiver;
    private String title;





    /******************************************************************************
     CONSTRUCTOR    : Email

     DESCRIPTION	:

     INPUT			: Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Email(String sender, String receiver, String title)
    {
        this(sender, receiver, title, "");
    }







    /******************************************************************************
     CONSTRUCTOR    : Email

     DESCRIPTION	:

     INPUT			: Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

                    : Type			: String
                    : Description	:

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
     METHOD		    : createMessage

     DESCRIPTION	: This method

     INPUT			: Type			: String
                    : Description	:

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void setEmailMessage(String emailMessage)
    {
        super.setText(emailMessage);
    }







    /******************************************************************************
     METHOD		    : getEmailMessage

     DESCRIPTION	: This method

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: New fraction.
     ******************************************************************************/
    public String getEmailMessage()
    {
        return super.getText();
    }


}
