/**
 * PROJECT:         Lab 3 - Question 2
 * FILE:            Account_Test.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 11, 2017
 * DESCRIPTION:     Per requirements. Test BankAccount methods.
 */


package Question2;


public class Account_Test {

    static Client C = new Client("Jason Choquette", "123456789", "123 Main St. Windsor, ON", "", "");
    static BankAccount bankAccount = new BankAccount("123456789");

    public static void testBankAccountMethods() {

        String acctNumber = bankAccount.getAccountNumber();
        System.out.print("\nClient: " + C.getName() +  "\nAccount number: " + acctNumber + "\nCurrent Balance: $" + bankAccount.getAccountBalance());

        System.out.print("\n\n=> Depositing $1,000.00\n");
        bankAccount.deposit(1000);
        System.out.print("\nClient: " + C.getName() +  "\nAccount number: " + acctNumber + "\nCurrent Balance: $" + bankAccount.getAccountBalance());

        System.out.print("\n\n=> Withdrawing $575.00\n");
        bankAccount.withdraw(575);
        System.out.print("\nClient: " + C.getName() +  "\nAccount number: " + acctNumber + "\nCurrent Balance: $" + bankAccount.getAccountBalance());

        // ClientIO Methods:

        // 1.  public static int getOptionFromUser(String inputDialog)
        // 2.  public static void showMenu(Client client)
        // 3.  public static void showExistingClientMenu(Client client)
        // 4.  public static Client getClientInfoFromUser()
        // 5.  public static String getClientNameFromInput()
        // 6.  public static String getClientSinFromInput()
        // 7.  public static String[] getClientAddressFromInput()
        // 8.  public static String getClientPhoneFromInput()
        // 9.  public static String getClientEmailFromInput()
        // 10. public static void updateClientInfo(Client client)
    }





    public static void testClient() {

        // Client Constructor:

        // 1. public Client(String n, String s, String[] a, String e, String p)


        // Client Methods:

        // 1.  public float makeWithdrawal(float amount)
        // 2. public float makeDeposit(float amount)
        // 3. public float getClientBalance()
        // 4. public String getClientSin()
    }





    public static void testBankAccount() {

        // BankAccount Methods:

        // 1. public float getAccountBalance()
        // 2. public float deposit(float amount)
        // 3. public float withdraw(float amount)
        // 4. public String getAccountInfo()
        // 5. public String createAcctNumber(String sin)
        // 6. private boolean sufficientFunds(float amount)
        // 7. public String getAccountNumber()
    }





    public static void testValidation() {

        // Validation Methods:

        // 1. public static String validateName(String clientName)
        // 2. public static String validateSIN(String sin)
        // 3. public static String[] validateAddress(String[] address)
        // 4. public static String validatePhone(String phone)
        // 5. public static String validateEmail(String email)
        // 6. public static boolean isValidPassword(String sin)
    }
}
