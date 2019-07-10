/**
 * PROJECT:     Lab 2 - Question 9
 * FILE:        Q9Customer.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: This is a simple class that represents a Customer object.
 */


public class Q9Customer {

    private static int acctNumber;
    private static int beginningBalance;
    private static int currentCharges;
    private static int currentPayments;
    private static int creditLimit;

    public Q9Customer(int an, int bb, int cc, int cp, int cl) {
        acctNumber          = an;
        beginningBalance    = bb;
        currentCharges      = cc;
        currentPayments     = cp;
        creditLimit         = cl;
    }

    public int getCustomerBalance(){ return beginningBalance + (currentCharges - currentPayments); }

    public int getCreditLimit() {
        return creditLimit;
    }

    public boolean creditLimitExceeded() {
        return getCustomerBalance() > getCreditLimit();
    }

} // end class Q9Customer
