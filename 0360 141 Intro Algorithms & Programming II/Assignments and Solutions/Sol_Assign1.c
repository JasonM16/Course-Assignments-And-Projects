/**
    This program expresses the factorial of a
    number N in terms of the numbers of times
    each prime number occurs in N!

    Written by: Quazi Rahman, May 2012.
**/

#include<stdio.h>


int find_prime_count(int prime, int number);
int find_next_prime(int number);
int IsPrime(int number);

int main()
{
    int factor, number, prime, prime_count, loop_counter;

    //printf("Enter a number: ");
    scanf("%d", &number);

    while(number > 0)
    {

        printf("\n%3d! = ", number);

        loop_counter = 0;

        //start with the smallest prime, 2
        prime = 2;

        while(prime <= number)
        {
            prime_count = 0;

            /* find the number of current prime number in
               all the factors, i.e. n, n-1, n-2, ..., 4, 3, 2
            */
            for(factor = number; factor > 1; factor--)
            {
                if(prime <= factor) //if the current prime is not greater than the factor
                {
                    prime_count += find_prime_count(prime, factor);
                }
            }

            // print this set (prime, prime_count)
            if (prime == 2)
                printf(" (%d^%d)", prime, prime_count);
            else
                printf("*(%d^%d)", prime, prime_count);

            //get the next prime number
            prime = find_next_prime(prime);

            //maintain output format
            if((++loop_counter) % 9 == 0) printf("\n       ");

        }

        printf("\n");
        scanf("%d", &number);
    }
}

/*
   This function counts how many times the number
   "prime" occurs in the number "number".
*/
int find_prime_count(int prime, int number)
{
    int count = 0;
    while(number % prime == 0)
    {
        count++;
        number = number / prime;
    }

    return count;
}


/*Finds the next prime number greater than the input
  INPUT: a positive integer n
  OUTPUT: prime number > n
*/

int find_next_prime(int number)
{
    int trial_prime;

    if(number == 1 || number == 2) return number + 1;  //for base cases

    //choose the next odd number
    if(number % 2 == 0)
        trial_prime = number + 1;
    else
        trial_prime = number + 2;

    while( !IsPrime (trial_prime) )
        //test the next odd number
        trial_prime += 2;

    //while loop will end only when we found a prime number
    return trial_prime;
}


/*Determines if a given number is prime or not
  INPUT: a positive integer n
  OUTPUT: 1, if n is prime, 0 otherwise
  OBSERVATIONS:
    1. A prime number must be an odd number
    2. An odd number can not be divided by an even number
*/

int IsPrime(int number)
{
    if(number == 2 || number == 3) return 1; //for base cases

    if(number % 2 == 0) return 0; //even numbers cannot be prime number

    int divisor = 3; //start with the smallest odd number (> 1) 3

    while(number % divisor != 0)
    {
        if(divisor * divisor > number) //"number" is a prime number
            return 1;

        divisor +=2; //check with the next (odd) divisor
    }
    return 0;
}