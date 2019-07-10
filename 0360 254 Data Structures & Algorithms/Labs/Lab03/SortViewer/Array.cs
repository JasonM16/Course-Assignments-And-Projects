/*
 * PROJECT          : Lab 3 
 * FILE             : Array.cs
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : Feb. 10, 2017
 * DESCRIPTION      : 
 */


using System;

namespace SortViewer
{
    public static class Array
    {
        /******************************************************************************
        FUNCTION		: Print

        DESCRIPTION		: This method prints the elements of the array.

        INPUT			: Type			: int[]
                        : Description	: The array elements.                   

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public static void Print(int[] A)
        {
            Console.Write("[");
            foreach (int a in A)
                Console.Write("{0} ", a);

            Console.Write("]");
        }





        /******************************************************************************
        FUNCTION		: GenerateRandomArray

        DESCRIPTION		: This method populates an array of size n with random numbers.

        INPUT			: Type			: int
                        : Description	: The size of the array.  
                        
                        : Type			: int
                        : Description	: The minimum value for a random number. 
                        
                        : Type			: int
                        : Description	: The maximum value for a random number.                        

        OUTPUT			: Type 			: int[]
                        : Description	: Returns the initalized array.
        ******************************************************************************/
        public static int[] GenerateRandomArray(int size, int min, int max)
        {
            int[] A = new int[size];
            Random rnd = new Random();

            for (int i = 0; i < size; i++)
                A[i] = rnd.Next(min, max); 
            
            return A;
        }
    }
}
