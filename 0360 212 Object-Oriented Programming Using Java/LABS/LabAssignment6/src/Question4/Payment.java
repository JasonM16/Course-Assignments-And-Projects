/**
 * PROJECT          : Lab 6 - Question 4
 * FILE             : Payment.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Define a class named Payment that contains an instance variable of type double that stores the
 *                    amount of the payment and appropriate accessor and mutator methods.
 *
 *                    Also create a method named paymentDetails that outputs an English sentence to describe the amount
 *                    of the payment.
 */


package Question4;

import java.text.NumberFormat;

// payments should be immutable. I.e., cancelled or new payments only
public class Payment
{
    private final double payment;



    /******************************************************************************
     CONSTRUCTOR    : Payment

     DESCRIPTION	: Payment constructor.

     INPUT			: Type			: double
                    : Description	: The payment amount.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Payment(double payment)
    {
        this.payment = payment;
    }






    /******************************************************************************
     METHOD		    : getPayment

     DESCRIPTION	: This method returns the payment amount.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: double
                    : Description	: The payment amount.
     ******************************************************************************/
    public double getPayment()
    {
        return this.payment;
    }







    /******************************************************************************
     METHOD		    : updatePayment

     DESCRIPTION	: This method updates a payment.

     INPUT			: Type			: double
                    : Description	: The payment amount.

     OUTPUT			: Type 			: Payment
                    : Description	: A new payment instance
     ******************************************************************************/
    // immutable
    public Payment updatePayment (double payment)
    {
        return new Payment(payment);
    }






    /******************************************************************************
     METHOD		    : paymentDetails

     DESCRIPTION	: This method prints the details of a payment.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void paymentDetails()
    {
        NumberFormat formatter = NumberFormat.getCurrencyInstance();
        System.out.println("Thank you for your payment of " + formatter.format(payment) + "\n");
    }


    public enum PaymentType
    {
        Cash,
        Credit
    }

}
