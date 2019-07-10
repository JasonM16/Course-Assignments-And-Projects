/*
 * PROJECT          : Lab 3 
 * FILE             : Program.cs
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : Feb. 10, 2017
 * DESCRIPTION      : 
 */




using System;
using System.Diagnostics;


namespace Lab03
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw1 = new Stopwatch();
            Stopwatch sw2 = new Stopwatch();

            var array = new[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
            array = new[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            array = new[]  { 1, 2, 4, 5, 3, 7, 8, 10, 11, 9, 6 };
            int arraySize = array.Length;
            int[] quickSortArray = new int[arraySize];
            
            array.CopyTo(quickSortArray,0); 

            //array = Array.GenerateRandomArray(50, 1, 10000);
            
            Console.Write("Before sort: ");
            Array.Print(array);
            sw1.Start();
            Sort.InsertionSort(array);
            sw1.Stop();
            Console.Write("After sort: ");
            Array.Print(array);
            TimeSpan ts1 = sw1.Elapsed;
            Console.WriteLine("InsertionSort took {0} Seconds to sort array of {1} integers.\n", ts1.Seconds, arraySize);

            Console.Write("Before sort: ");
            Array.Print(quickSortArray);
            sw2.Start();
            Sort.QuickSort(quickSortArray, 0, array.Length - 1);
            sw2.Stop();
            Console.Write("After sort: ");
            Array.Print(quickSortArray);
            TimeSpan ts2 = sw2.Elapsed;
            Console.WriteLine("QuickSort took {0} Seconds to sort array of {1} integers.\n", ts2.Seconds, arraySize);
            
            Console.ReadLine();
        }
    }
}
