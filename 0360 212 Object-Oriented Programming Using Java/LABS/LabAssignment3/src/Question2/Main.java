/**
 * PROJECT:         Lab 3 - Question 2
 * FILE:            Main.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 10, 2017
 * DESCRIPTION:     This class runs the program's user menus.

 */


package Question2;
public class Main {

    public static void main(String[] args) {

        boolean test = true;
        if (test)
            Account_Test.testBankAccountMethods();

        else
            runNewClientMenu();
    }




    /******************************************************************************
     METHOD		    : runNewClientMenu

     DESCRIPTION	: This method displays a menu to the client.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    static void runNewClientMenu() {

        String userInput = Client.IO.getUserInput(" 1. Create Account \n" + " 2. Quit \n");
        int option = Integer.parseInt(userInput);

        switch (option) {

            case 1:
                Client client = ClientBuilder.createNewClient(); // create a new client
                runExistingClientMenu(client); // once client has been created, show the existing client menu
                break;

            case 2:
                System.exit(0);
                break;

            default:
                Client.IO.showUserMessage("Not a valid option.", "Error", 0);
                break;
        }
    }




    /******************************************************************************
     METHOD		    : runExistingClientMenu

     DESCRIPTION	: This method displays a menu to the user to perform account
                      transactions.

     INPUT			: Type			: Client
                    : Description	: Used to obtain the client's information.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    static void runExistingClientMenu(Client client) {

        String existingUserMenu = " 1. Account Balance \n 2. Make Deposit \n 3. Make Withdrawal \n " +
                "4. Update Account Information \n 5. Logout \n";

        while (true) {

            String userInput = Client.IO.getUserInput(existingUserMenu);
            int option = Integer.parseInt(userInput);

            switch (option) {

                case 1:
                    Client.IO.PrintBalance(client.getAccountBalance());
                    break;

                case 2:
                    Client.Transaction.deposit();
                    Client.IO.PrintBalance(client.getAccountBalance());
                    break;

                case 3:
                    Client.Transaction.withdraw();
                    Client.IO.PrintBalance(client.getAccountBalance());
                    break;

                case 4:
                    ClientBuilder.updateClient(client);
                    break;

                case 5:
                    System.exit(0);

                default:
                    Client.IO.showUserMessage("Not a valid option.", "Error", 0);
                    break;
            }
        }
    }
}
