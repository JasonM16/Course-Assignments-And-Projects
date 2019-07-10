/**
 * PROJECT          : Lab 6 - Question 5
 * FILE             : Main.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Create several sample objects of type Email and File in your main method.
 *                    Test your objects by passing them to the following subroutine that returns true if the object
 *                    contains the specified keyword in the text property.
 */


package Question5;


public class Main
{
    public static void main(String[] args)
    {
        String title        = "C# vs. Java vs. Python";
        String text         = "This is just some sample text.\nThis is on a new line!";
        String updatedText  = "This is the updated text. We should see if this text contains the word 'updated' and " +
                "'sunshine'. \nThese should return true and false, respectively";
        String pathName     = "/some_path/some_document";
        String sender       = "Mr. Anders Hejlsberg";
        String receiver     = "Mr. James Gosling, cc: Guido van Rossum";

        Document doc1 = new Document(text);

        File file1 = new File(pathName);
        file1.setText(text);

        Email email1 = new Email(sender, receiver, title, "I think most people should learn all of the languages. " +
                "Do you guys agree??");


        System.out.println("\n");
        System.out.println("email1 text contains the word 'disagree' : " + Document.Contains(email1, "disagree"));
        System.out.println("email1 text contains the word 'agree'    : " + Document.Contains(email1, "agree"));
        System.out.println("\n");
        System.out.println("file1  text contains the word 'sunshine' : " + Document.Contains(file1, "sunshine"));
        System.out.println("file1  text contains the word 'updated'  : " + Document.Contains(file1, "updated"));
        System.out.println("doc1   text contains the word 'sunshine' : " + Document.Contains(doc1, "sunshine"));
        System.out.println("doc1   text contains the word 'up dated' : " + Document.Contains(doc1, "up dated"));

        doc1.setText(updatedText);
        file1.setText(updatedText);

        System.out.println("\ndoc1 and file1 text updated!\n");
        System.out.println("file1 text contains the word 'sunshine'  : " + Document.Contains(file1, "sunshine"));
        System.out.println("file1 text contains the word 'updated'   : " + Document.Contains(file1, "updated"));
        System.out.println("doc1  text contains the word 'sunshine'  : " + Document.Contains(doc1, "sunshine"));
        System.out.println("doc1  text contains the word 'up dated'  : " + Document.Contains(doc1, "up dated"));

        file1.setText("This is different text!!");

        System.out.println(file1);
        System.out.println(doc1);
        System.out.println(email1);
    }
}
