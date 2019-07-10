/**
 * PROJECT          : Lab 6 - Question 4
 * FILE             : CashPayment.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Define a class named CashPayment that is derived from Payment.
 *                    This class should redefine the paymentDetails method to indicate that the payment is in cash.
 *                    Include appropriate constructor(s).
 */


package Question4;


public class CashPayment extends Payment
{
    private final double payment;



    /******************************************************************************
     CONSTRUCTOR    : CashPayment

     DESCRIPTION	: CashPayment constructor

     INPUT			: Type			: double
                    : Description	: The payment amount.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public CashPayment(double payment)
    {
        super(payment);
        this.payment = payment;
    }






    /******************************************************************************
     METHOD		    : paymentDetails

     DESCRIPTION	: This method prints the details of a cash payment.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void paymentDetails()
    {
        System.out.println("Payment type: Cash");
        super.paymentDetails();
    }
}
