/**
 * PROJECT          : Lab 6 - Question 4
 * FILE             : CreditCardPayment.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Define a class named CreditCardPayment that is derived from Payment . This class should
 *                    contain instance variables for the name on the card, expiration date, and credit card number.
 *                    Include appropriate constructor(s).
 *                    Finally, redefine the paymentDetails method to include all credit card information in the printout.
 */


package Question4;


public class CreditCardPayment extends Payment
{
    private final double payment;
    private final String cardHolderName;
    private final String expirationDate;
    private final int    creditCardNumber;





    /******************************************************************************
     CONSTRUCTOR    : CreditCardPayment

     DESCRIPTION	: CreditCardPayment constructor

     INPUT			: Type			: double
                    : Description	: The payment amount.

                    : Type			: String
                    : Description	: The credit card owner's name.

                    : Type			: String
                    : Description	: The credit card's expiration date.

                    : Type			: int
                    : Description	: The credit card number.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public CreditCardPayment(double payment, String cardHolderName, String expirationDate, int creditCardNumber)
    {
        super(payment);
        this.payment = payment;
        this.cardHolderName = cardHolderName;
        this.expirationDate = expirationDate;
        this.creditCardNumber = creditCardNumber;
    }





    /******************************************************************************
     METHOD		    : paymentDetails

     DESCRIPTION	: This method prints the details of a credit card payment.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void paymentDetails()
    {
        System.out.println("Account Number: " + creditCardNumber + "\nCardholder: " + cardHolderName + "\nExpiration Date: " +
        expirationDate);
        super.paymentDetails();
    }
}
