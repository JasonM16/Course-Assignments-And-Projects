/**
 * PROJECT:         Lab 3 - Question 2
 * FILE:            Client.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 10, 2017
 * DESCRIPTION:     This class represents a client of a bank. The Client class also contains classes for:
 *
 *                  1. User IO;
 *                  2. Account Transactions.
 */


package Question2;
import javax.swing.*;
import java.text.NumberFormat;



public class Client {

    // member variables
    private String        name;
    private String        address;
    private String        sin;
    private String        email;
    private String        phone;
    private String        acctNumber;
    private static BankAccount   account;


    /******************************************************************************
     CONSTRUCTOR    : Client

     DESCRIPTION	: Client constructor.

     INPUT			: Type			: String
                    : Description	: The client's name.


                    : Type			: String
                    : Description	: The client's social insurance number.

                    : Type			: Address
                    : Description	: The client's address.

                    : Type			: Email
                    : Description	: The client's email (optional).

                    : Type			: String
                    : Description	: The client's phone number (optional).

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Client(String n, String s, String a, String e, String p) {

        name = n;
        sin = s;
        address = a;
        email = e;
        phone = p;
        account = new BankAccount(sin);
        acctNumber = account.getAccountNumber();
    }




    // setters
    public void setName(String name) {
        this.name = name;
    }
    public void setAddress(String address) {
        this.address = address;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public void setPhone(String phone) {
        this.phone = phone;
    }


    // getters
    public String getName() {
        return name;
    }
    public String getAddress() {
        return address;
    }
    public String getEmail() {
        return email;
    }
    public String getPhone() {
        return phone;
    }





    /******************************************************************************
     METHOD		    : getAccountBalance

     DESCRIPTION	: This method calls into the client's bank account and returns
                      the bank account balance.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: float
                    : Description	: The client's current accountbalance.
     ******************************************************************************/
    public float getAccountBalance() { return account.getAccountBalance(); }




    /******************************************************************************
     METHOD		    : withdraw

     DESCRIPTION	: This method calls into the client's bank account and withdraws
                      the amount requested from the client's bank account.

     INPUT			: Type			: float
                    : Description	: The amount to be withdrawn from the account.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private static void withdraw(float amount) { account.withdraw(amount); }




    /******************************************************************************
     METHOD		    : deposit

     DESCRIPTION	: This method calls into the client's bank account and deposits
                      the amount requested to the client's bank account.

     INPUT			: Type			: float
                    : Description	: The amount to be deposited in the account.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private static void deposit(float amount) { account.deposit(amount); }





    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method returns a formatted string with the pertinent
                      client information

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: Returns the formatted string.
     ******************************************************************************/
    public String toString()
    {
        return name + "\t" + acctNumber + "\n" + address + "\n";
    }




    /******************************************************************************
     CLASS		    : Transaction

     DESCRIPTION	: This class represents account transactions
     ******************************************************************************/
    public static class Transaction {


        /******************************************************************************
         METHOD		    : withdraw

         DESCRIPTION	: This method obtains the requested withdrawal amount from the
                          client. It also ensures the amount is positive and that there
                          are sufficient funds in the account. If the amount is valid,
                          it is withdrawn from the account.

         INPUT			: Type			: void
                        : Description	: N/A

         OUTPUT			: Type 			: void
                        : Description	: N/A
         ******************************************************************************/
        public static void withdraw() {
            String withdrawal = IO.getUserInput("Withdrawal amount: ");
            float amount = Float.parseFloat(withdrawal);

            if(Validation.isValidateWithdrawal(account.getAccountBalance(), amount))
                Client.withdraw(amount);
        }





        /******************************************************************************
         METHOD		    : deposit

         DESCRIPTION	: This method obtains the requested deposit amount from the
                          client. It also ensures the amount is positive. If the amount
                          is valid, it is deposited in the account.

         INPUT			: Type			: void
                        : Description	: N/A

         OUTPUT			: Type 			: void
                        : Description	: N/A
         ******************************************************************************/
        public static void deposit() {

            String deposit = IO.getUserInput("Deposit amount: ");
            float amount = Float.parseFloat(deposit);

            if(Validation.positiveAmount(amount))
                Client.deposit(amount);
        }
    }



    /******************************************************************************
     CLASS		    : IO

     DESCRIPTION	: This class contains all the methods for user IO.
     ******************************************************************************/
    public static class IO {



        /******************************************************************************
         METHOD		    : getUserInput

         DESCRIPTION	: This method obtains user input from an input dialog.

         INPUT			: Type			: String
                        : Description	: The message to show to the user.

         OUTPUT			: Type 			: String
                        : Description	: The user's input.
         ******************************************************************************/
        public static String getUserInput(String inputDialog) {

            return JOptionPane.showInputDialog(inputDialog);
        }





        /******************************************************************************
         METHOD		    : getUserInput

         DESCRIPTION	: This method obtains user input from an input dialog.

         INPUT			: Type			: String
                        : Description	: The message to show to the user.

                        : Type			: String
                        : Description	: Default text to be displayed in the input dialog.

         OUTPUT			: Type 			: String
                        : Description	: The user's input.
         ******************************************************************************/
        public static String getUserInput(String message, String initialSelectionValue) {

            return JOptionPane.showInputDialog(null, message, initialSelectionValue);
        }





        /******************************************************************************
         METHOD		    : showUserMessage

         DESCRIPTION	: This method displays a message to user.

         INPUT			: Type			: String
                        : Description	: The message to show to the user.

         OUTPUT			: Type 			: void
                        : Description	: N/A
         ******************************************************************************/
        public static void showUserMessage(String message) {

            JOptionPane.showMessageDialog(null, message);
        }





        /******************************************************************************
         METHOD		    : showUserMessage

         DESCRIPTION	: This method displays a message to user.

         INPUT		    : Type			: String
                        : Description	: The message to show to the user.

                        : Type			: String
                        : Description	: The title of the message dialog.

                        : Type			: int
                        : Description	: The message type. i.e., MESSAGE_TYPE.ERROR

         OUTPUT			: Type 			: void
                        : Description	: N/A
         ******************************************************************************/
        public static void showUserMessage(String message, String title, int messageType) {

            JOptionPane.showMessageDialog(null, message, title, messageType);
        }





        /******************************************************************************
         METHOD		    : PrintBalance

         DESCRIPTION	: This method prints the client's current account balance.

         INPUT			: Type			: float
                        : Description	: The client's account balance.

         OUTPUT			: Type 			: void
                        : Description	: N/A
         ******************************************************************************/
        public static void PrintBalance(float balance) {

            NumberFormat formatter = NumberFormat.getCurrencyInstance();
            String balanceString = formatter.format(balance);

            showUserMessage("Current Balance: " + balanceString);
        }
    }
}
