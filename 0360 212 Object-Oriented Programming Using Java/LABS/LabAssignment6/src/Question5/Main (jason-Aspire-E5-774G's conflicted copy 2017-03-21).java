/**
 * PROJECT:         Lab 6 - Question 5
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   March 18, 2017
 * REQUIREMENTS:    Define a class named Document that contains an instance variable of type String named text that
                    stores any textual content for the document.
                    Create a method named toString that returns the text field and also include a method to set this value.

                    Next, define a class for Email that is derived from Document and includes instance variables for
                    the sender, recipient, and title of an email message.
                    Implement appropriate accessor and mutator methods.

                    The body of the email message should be stored in the inherited variable text.
                    Redefine the toString method to concatenate all text fields.

                    Similarly, define a class for File that is derived from Document and includes a instance variable
                    for the pathname.
                    The textual contents of the file should be stored in the inherited variable text.
                    Redefine the toString method to concatenate all text fields.
 */


package Question5;


public class Main
{
    public static void main(String[] args)
    {
        File f1 = new File("./some_path/some_file");

        f1.setText("This is some text!!!");
        Document d1 = new Document("Hello World");
        Email e1 = new Email("Jason C. ", "Mike Ekim","Re: Java Programming");
    }
}
