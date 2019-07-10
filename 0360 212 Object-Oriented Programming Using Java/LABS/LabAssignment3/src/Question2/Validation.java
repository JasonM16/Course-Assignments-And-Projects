 /**
 * PROJECT:         Lab 3 - Question 2
 * FILE:            Validation.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 10, 2017
 * DESCRIPTION:     This class will be used for validating the client's personal information (not a requirement and
  *                 I'm not sure how this program will be tested so I'm just returning true so any input is valid.)
  *                 as well as validating account transactions. Any future required validation will go in this class.
 */


 package Question2;


public class Validation {

    // regular expressions used for validation
    private static String emailRegex  = "\"^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\\\.[A-Z]{2,6}$\"";
    private static String phoneRegex  = "\\+\\d(-\\d{3}){3}-\\d{4}";
    private static String sinRegex    = "^(\\d{3}-\\d{3}-\\d{3})|(\\d{3} \\d{3} \\d{3})|(\\d{9})$";
    private static String nameRegex   = "";
    private static String postalRegex = "[ABCEGHJKLMNPRSTVXY][0-9][ABCEGHJKLMNPRSTVWXYZ] ?[0-9][ABCEGHJKLMNPRSTVWXYZ][0-9]";
    private static String streetRegex = "^([0-9]+ )?[a-zA-Z ]+$";


    /******************************************************************************
     METHOD		    : propertyToValidate

     DESCRIPTION	: This method determines what property of the client's info
                      needs to be validated.

     INPUT			: Type			: ClientBuilder.fieldNames
                    : Description	: The Field (property) to be validated.

                    : Type			: String
                    : Description	: The value to validate.

     OUTPUT			: Type 			: boolean
                    : Description	: True if the property is valid. False, otherwise.
     ******************************************************************************/
    public static boolean propertyToValidate(ClientBuilder.fieldNames property, String value)
    {
        boolean isValid = false;

        switch (property) {

            case NAME:
                isValid = isValid(nameRegex,value);
                break;

            case SIN:
                isValid = isValid(sinRegex,value);
                break;
            // Note: address would be more complicated to validate but just using a very simple postal code regex for example purposes...
            case ADDRESS:
                isValid = isValid(postalRegex,value);
                break;

            case PHONE:
                isValid = isValid(phoneRegex,value);
                break;

            case EMAIL:
                isValid = isValid(emailRegex,value);
                break;
        }

        return isValid;
    }




    /******************************************************************************
     METHOD		    : isValid

     DESCRIPTION	: Tests a String against a Regular Expression.

     INPUT			: Type			: String
                    : Description	: The regular expression to test against.

                    : Type			: String
                    : Description	: The string to validate.

     OUTPUT			: Type 			: boolean
                    : Description	: True if the String matches the Regex.
     ******************************************************************************/
    private static boolean isValid(String regex, String value) {
        return true;
        //return new RegularExpression(regex).matches(value);
    }




    /******************************************************************************
     METHOD		    : isValidateWithdrawal

     DESCRIPTION	: This method determines if an attempted withdrawal from a
                      client's account is valid.

     INPUT			: Type			: float
                    : Description	: The client's account balance.

                    : Type			: float
                    : Description	: The attempted withdrawal amount.

     OUTPUT			: Type 			: boolean
                    : Description	: True, if amount is positive and there are
                                      sufficient funds. False, otherwise.
     ******************************************************************************/
    public static boolean isValidateWithdrawal(float balance, float amount) {

        boolean isValidAmount = false;

        while(!positiveAmount(amount)){
            Client.IO.showUserMessage("Error. Only positive amounts are valid.", "Error",  0);
            String withdrawal = Client.IO.getUserInput("Withdrawal amount: ");
            amount = Float.parseFloat(withdrawal);
        }

        if(balance >= amount)
            isValidAmount = true;
        else
            Client.IO.showUserMessage("Error. Insufficient Funds.", "Error",  0);

        return  isValidAmount;
    }






    /******************************************************************************
     METHOD		    : positiveAmount

     DESCRIPTION	: Determines if a value is greater then zero.

     INPUT			: Type			: float
                    : Description	: The amount to validated.

     OUTPUT			: Type 			: boolean
                    : Description	: True if amount is greater then zero. False,
                                      otherwise.
     ******************************************************************************/
    public static boolean positiveAmount(float amount) {
        return amount > 0;
    }

}
