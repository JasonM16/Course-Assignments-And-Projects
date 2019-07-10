/**
 * PROJECT:         Lab 3 - Question 2
 * FILE:            BankAccount.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   February 10, 2017
 * DESCRIPTION:     This method represents a Bank Account
 */


package Question2;
import java.util.concurrent.ThreadLocalRandom;


public class BankAccount {

    // member variables
    private float balance;
    private String acctNumber;



    /******************************************************************************
     CONSTRUCTOR    : BankAccount

     DESCRIPTION	: BankAccount constructor.

     INPUT			: Type			: String
                    : Description	: The client's Social Insurance Number.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public BankAccount(String clientSin)
    {
        balance = 0.0f;
        acctNumber = createAcctNumber(clientSin);
    }




    // getters
    public float getAccountBalance() { return balance; }
    public String getAccountNumber() { return acctNumber; }




    /******************************************************************************
     METHOD		    : deposit

     DESCRIPTION	: This method deposits the amount into the client's account.

     INPUT			: Type			: float
                    : Description	: The amount to deposit to the account.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void deposit(float amount) { balance += amount; }






    /******************************************************************************
     METHOD		    : withdraw

     DESCRIPTION	: This method withdraws the amount from the client's account.

     INPUT			: Type			: float
                    : Description	: The amount to withdraw from the account.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void withdraw(float amount) { balance -= amount; }




    /******************************************************************************
     METHOD		    : createAcctNumber

     DESCRIPTION	: This method creates a new client account number using the
                      client's Social Insurance Number and a random number.

     INPUT			: Type			: String
                    : Description	: the client's Social Insurance Number.

     OUTPUT			: Type 			: String
                    : Description	: the created account number.
     ******************************************************************************/
    private String createAcctNumber(String clientSin) {
        int rnd = ThreadLocalRandom.current().nextInt(1000, 10000);
        clientSin += "-";
        return clientSin += Integer.toString(rnd);
    }
}
