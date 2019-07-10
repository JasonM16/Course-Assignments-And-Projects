/**
 * PROJECT          : Lab 6 - Question 4
 * FILE             : Main.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 21, 2017
 * REQUIREMENTS     : Create a main method that creates at least two CashPayment and two CreditCardPayment objects
 *                    with different values and calls paymentDetails for each.
 */


package Question4;


public class Main
{
    public static void main (String[] args)
    {
        Payment payment = new Payment(125.00);
        CashPayment cash1 = new CashPayment(385.00);
        CreditCardPayment credit1 = new CreditCardPayment(25_000, "John H. CardHolder", "05/2020", 123456789);

        CashPayment cash2 = new CashPayment(50.00);
        CreditCardPayment credit2 = new CreditCardPayment(1375.00, "Susan M. CardHolder", "11/2019", 159785412);

        cash1.paymentDetails();
        cash2.paymentDetails();
        credit1.paymentDetails();
        credit2.paymentDetails();
    }
}
