/*
 * PROJECT          : Lab 3 
 * FILE             : Sort.cs
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : Feb. 10, 2017
 * DESCRIPTION      : 
 */


using System;

namespace SortViewer
{
    public static class Sort
    {
        /******************************************************************************
        FUNCTION		: QuickSort

        DESCRIPTION		: This method sorts an array of integers using the Quicksort
                          algorithm.

        INPUT			: Type			: int[]
                        : Description	: The unsorted array.
                        
                        : Type			: int
                        : Description	: The indexed position of the 'left' subarray.
                        
                        : Type			: int
                        : Description	: The indexed position of the 'right' subarray.

        OUTPUT			: Type 			: int[]
                        : Description	: Returns the sorted array.
        ******************************************************************************/
        public static int[] QuickSort(int[] S, int l, int r)
        {
            Console.Write("Just entered Quicksort with Array "); Array.Print(S); Console.Write("  Left Index Position: {0}  Right Index Position: {1}", l, r);


            //Console.Write("\n\nif ({0} >= {1}) return ", l, r); Array.Print(S);
            if (l >= r) return S;
            
            int p = S[r];
            Console.WriteLine("\n\nSentinal: {0}", p);

            int left = l;
            Console.WriteLine("Current Left Index Position in Array: {0}", left);

            int right = r - 1;
            Console.WriteLine("Current Right Index Position in Array: {0}\n", right);

            Console.WriteLine("Entering while(left <= right)");
            while (left <= right)
            {
                Console.WriteLine("\nFirst while loop: while ({0} <= {1} && {2} <= {3}) => left += 1", left, right, S[left], p);
                while (left <= right && S[left] <= p)
                    left += 1;

                Console.WriteLine("Second while loop: while ({0} <= {1} && {2} >= {3}) => right -= 1", left, right, S[right], p);
                while (left <= right && S[right] >= p)
                    right -= 1;

                Console.WriteLine("\nif({0} < {1}) => exchange {2} and {3} ", left, right, S[left], S[right]);
                if (left < right)
                    Exch(S, left, right);
            }

            Console.Write("Exchanging elements: {0} and {1}\n", S[left], S[r]);
            Exch(S, left, r);
            Console.Write("\n\n***Calling First Recursive call to Quicksort***\n\n");
            QuickSort(S, l, left - 1);
            Console.Write("\n\n***Calling Second Recursive call to Quicksort***\n\n");
            QuickSort(S, left + 1, r);

            Console.Write("\n\n===> Returning From QuickSort with Array "); Array.Print(S); Console.WriteLine(" <===");
            return S;
        }





        /******************************************************************************
        FUNCTION		: InsertionSort

        DESCRIPTION		: This method sorts an array of integers using the Insertion-
                          sort algorithm.

        INPUT			: Type			: int[]
                        : Description	: The unsorted array.                        

        OUTPUT			: Type 			: int[]
                        : Description	: Returns the sorted array.
        ******************************************************************************/
        public static int[] InsertionSort(int[] A)
        {
            for (int j = 1; j < A.Length; j++)
            {
                int key = A[j];
                int i = j - 1;
                while (i >= 0 && A[i] > key)
                {
                    Exch(A, i + 1, i);
                    i -= 1;
                }

                A[i + 1] = key;
            }

            return A;
        }




        /******************************************************************************
        FUNCTION		: Exch

        DESCRIPTION		: This method exchanges elements in an array.

        INPUT			: Type			: int[]
                        : Description	: An array of integers.    
                        
                        : Type			: int
                        : Description	: The index of the first element to be exchanged.  
                        
                        : Type			: int
                        : Description	: The index of the second element to be exchanged.

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        private static void Exch(int[] A, int i, int j)
        {
            int swap = A[i];
            A[i] = A[j];
            A[j] = swap;
        }
    }
}
