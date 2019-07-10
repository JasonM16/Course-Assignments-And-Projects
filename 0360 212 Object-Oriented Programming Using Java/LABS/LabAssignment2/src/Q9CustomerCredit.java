/**
 * PROJECT:     Lab 2 - Question 9
 * FILE:        Q9CustomerCredit.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Develop a Java application that determines whether any of several department-store customers has
                exceeded the credit limit on a charge account. For each customer, the following facts are available:

                 a) account number
                 b) balance at the beginning of the month
                 c) total of all items charged by the customer this month
                 d) total of all credits applied to the customer’s account this month
                 e) allowed credit limit.

                The program should input all these facts as integers, calculate the new balance
                (= beginning balance + charges – credits), display the new balance and determine whether the new
                balance exceeds the customer’s credit limit. For those customers whose credit limit is exceeded,
                the program should display the message "Credit limit exceeded".
 *
 */


public class Q9CustomerCredit {

    public static void main(String[] args) {

        int accountNumber    = 987654;
        int beginningBalance = 100;
        int currentCharges   = 1200;
        int currentPayments  = 0;
        int creditLimit      = 1250;

        Q9Customer customer = new Q9Customer(accountNumber, beginningBalance, currentCharges, currentPayments, creditLimit);

        System.out.print("Current balance: $" + customer.getCustomerBalance());
        if(customer.creditLimitExceeded()) {
            System.out.print("  **CREDIT LIMIT EXCEEDED**  ($" +
                    (customer.getCustomerBalance() - customer.getCreditLimit()) + " over limit)");
        }
    }

} // end class Q9CustomerCredit
