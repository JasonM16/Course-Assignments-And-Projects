/*
 * PROJECT          : Lab 4 
 * FILE             : Sort.cs
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : Mar. 04, 2017
 * DESCRIPTION      : 
 */


namespace Lab04
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
            if (l >= r) return S;
            int p = S[r];
            int left = l;
            int right = r - 1;
            // could be factored to a 'Partition' function...
            while (left <= right)
            {
                while (left <= right && S[left] <= p)
                    left += 1;

                while (left <= right && S[right] >= p)
                    right -= 1;

                if (left < right)
                    Exch(S, left, right);
            }

            Exch(S, left, r);
            QuickSort(S, l, left - 1);
            QuickSort(S, left + 1, r);

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
