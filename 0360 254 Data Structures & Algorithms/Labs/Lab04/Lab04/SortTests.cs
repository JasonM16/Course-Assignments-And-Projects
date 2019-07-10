using System;
using System.Diagnostics;

namespace Lab04
{
    public class SortTests
    {
        // 
        static Stopwatch sw1 = new Stopwatch();
        static Stopwatch sw2 = new Stopwatch();
        static Stopwatch sw3 = new Stopwatch();

        // Default arrays:
        //int[] random = new[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        //int[] random = new[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        //int[] random = new[] { 1, 3, 5, 7, 9, 10, 8, 6, 4, 2 };


        // generate a random array...
        static int[] random = GenerateRandomArray(size: 10_000, min: 1, max: 500);

        static KVP<int, string>[] A = GenerateRandomKvpArray(random);


        private static void Insertion_Sort()
        {            
            int[] copy = new int[random.Length];
            random.CopyTo(copy, 0);
            sw1.Start();
            Sort.InsertionSort(copy);
            sw1.Stop();
        }

        private static void Quick_Sort()
        {           
            int[] copy = new int[random.Length];
            random.CopyTo(copy, 0);
            sw2.Start();
            Sort.QuickSort(random, 1, random.Length - 1);
            sw2.Stop();
        }


        private static void Heap_Sort()
        {            
            sw3.Start();
            Heap<int, string>.HeapSort(A);   
            sw3.Stop();
        }


        public static void RunTests()
        {
            Insertion_Sort();
            Quick_Sort();
            Heap_Sort();
        }

        public static void PrintResults()
        {
            var insertion_sort_time = sw1.ElapsedMilliseconds;
            var quick_sort_time     = sw2.ElapsedMilliseconds;
            var heap_sort_time      = sw3.ElapsedMilliseconds;
            var numberofItems       = random.Length;

            Console.WriteLine("SORTING TIMES:\n----------------------");
            Console.WriteLine("Insertion-Sort took {0} milliseconds to sort {1} items.\n", insertion_sort_time, numberofItems);
            Console.WriteLine("Quick-Sort took {0} milliseconds to sort {1} items.\n", quick_sort_time, numberofItems);
            Console.WriteLine("Heap-Sort took {0} milliseconds to sort {1} items.\n", heap_sort_time, numberofItems);
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
        private static int[] GenerateRandomArray(int size, int min, int max)
        {
            int[] A = new int[size];
            Random rnd = new Random();

            for (int i = 0; i < size; i++)
                A[i] = rnd.Next(min, max);

            return A;
        }


        /******************************************************************************
        FUNCTION		: GenerateRandomKvpArray

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
        private static KVP<int, string>[] GenerateRandomKvpArray(int[] array)
        {
            var A = new KVP<int, string>[array.Length];            

            for (int i = 0; i < array.Length; i++)
                A[i] = new KVP<int, string> { Key = array[i], Value = "" };

            return A;
        }

    }
}
