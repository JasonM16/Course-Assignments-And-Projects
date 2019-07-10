/**
 * PROJECT:         Lab 6 - Question 4
 * FILE:            Payment.java
 * AUTHOR:          Jason Choquette - 104337378
 * LAST MODIFIED:   March 18, 2017
 * DESCRIPTION:
 */


package Question4;

// immutable
public class Payment
{
    private final double payment;





    /******************************************************************************
     CONSTRUCTOR    : Payment

     DESCRIPTION	:

     INPUT			: Type			: double
                    : Description	:

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Payment(double payment)
    {
        this.payment = payment;
    }






    /******************************************************************************
     METHOD		    : getPayment

     DESCRIPTION	: This

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: double
                    : Description	:
     ******************************************************************************/
    public double getPayment()
    {
        return this.payment;
    }







    /******************************************************************************
     METHOD		    : updatePayment

     DESCRIPTION	: This

     INPUT			: Type			: double
                    : Description	:

     OUTPUT			: Type 			: Payment
                    : Description	:
     ******************************************************************************/
    // immutable
    public Payment updatePayment (double payment)
    {
        return new Payment(payment);
    }






    /******************************************************************************
     METHOD		    : paymentDetails

     DESCRIPTION	:

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void paymentDetails()
    {

    }

}
