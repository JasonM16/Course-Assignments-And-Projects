/**
 * PROJECT:         Lab 3 - Question 2
 * FILE:            ClientBuilder.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 10, 2017
 * DESCRIPTION:     This class creates and updates Client objects.
 */


package Question2;


public class ClientBuilder {

    // member variables
    private static String name;
    private static String sin;
    private static String address;
    private static String phone;
    private static String email;
    private static String[] fields =
            {
                    "Name (first and last)",
                    "Social Insurance Number",
                    "Home Address",
                    "Phone Number",
                    "Email Address"
            };





    /******************************************************************************
     METHOD		    : updateClient

     DESCRIPTION	: This method updates the validated client info.

     INPUT			: Type			: Client
                    : Description	: The client to be updated.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public static void updateClient(Client client)
    {
        name    = Client.IO.getUserInput("Update Name: "          , client.getName());
        address = Client.IO.getUserInput("Update Address: "       , client.getAddress());
        phone   = Client.IO.getUserInput("Update Phone Number: "  , client.getPhone());
        email   = Client.IO.getUserInput("Update Email Address: " , client.getEmail());

        client.setName(name);
        client.setAddress(address);
        client.setPhone(phone);
        client.setEmail(email);
    }





    /******************************************************************************
     METHOD		    : createNewClient

     DESCRIPTION	: This method obtains the validated client info and then returns
                      a newly created client.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: Client
                    : Description	: The newly created client.
     ******************************************************************************/
    public static Client createNewClient()
    {
        name    = obtainAndValidateInput(fieldNames.NAME,    name,    errorMessage(0), inputMessage(0));
        sin     = obtainAndValidateInput(fieldNames.SIN,     sin,     errorMessage(1), inputMessage(1));
        address = obtainAndValidateInput(fieldNames.ADDRESS, address, errorMessage(2), inputMessage(2));
        phone   = obtainAndValidateInput(fieldNames.PHONE,   phone,   errorMessage(3), inputMessage(3));
        email   = obtainAndValidateInput(fieldNames.EMAIL,   email,   errorMessage(4), inputMessage(4));

        return new Client(name, sin, address, phone, email);
    }





    /******************************************************************************
     METHOD		    : obtainAndValidateInput

     DESCRIPTION	: This method reads in the client's information until the information
                      is valid and sets those values.

     INPUT			: Type			: ClientBuilder.fieldNames
                    : Description	: The field name.

                    : Type			: String
                    : Description	: The value to be stored from user input.

                    : Type			: String
                    : Description	: The error message if the property is not valid.

                    : Type			: String
                    : Description	: Which property do we need from the user.

     OUTPUT			: Type 			: String
                    : Description	: The validated property.
     ******************************************************************************/
    private static String obtainAndValidateInput(fieldNames property, String value, String errorMessage, String fieldToSet) {

        value = Client.IO.getUserInput(fieldToSet);
        while (!Validation.propertyToValidate(property, value)) {
            Client.IO.showUserMessage(errorMessage, "Error",  0); // JOptionPane.ERROR_MESSAGE = 0
            value = Client.IO.getUserInput(fieldToSet);
        }

        return value;
    }






    /******************************************************************************
     METHOD		    : errorMessage

     DESCRIPTION	: Builds an error message to be displayed to the user when a
                      property is invalid.

     INPUT			: Type			: int
                    : Description	: The invalid property info obtained from user.

     OUTPUT			: Type 			: String
                    : Description	: The result of the output dialog
     ******************************************************************************/
    public static String errorMessage(int property) {

        return "Error. Invalid " + fields[fieldNames.values()[property].ordinal()] + ". ";
    }





    /******************************************************************************
     METHOD		    : inputMessage

     DESCRIPTION	: Builds an input message to obtain property info from the user.

     INPUT			: Type			: int
                    : Description	: The property to obtain from user.

     OUTPUT			: Type 			: String
                    : Description	: The result of the input dialog.
     ******************************************************************************/
    public static String inputMessage(int property) {
        return "Please enter your " + fields[fieldNames.values()[property].ordinal()] + ": ";
    }





    /******************************************************************************
     enum		    : fieldNames

     DESCRIPTION	: An enum to store the properties of the client's account

     INPUT			: Type			: N/A
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public enum fieldNames {

        NAME,
        SIN,
        ADDRESS,
        PHONE,
        EMAIL
    }
}
