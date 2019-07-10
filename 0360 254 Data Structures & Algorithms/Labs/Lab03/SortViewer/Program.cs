using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortViewer
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num1 = {8,3,5,9,1,2,6,4,7};
            int[] num2 = {8, 3, 5, 9};

            Sort.QuickSort(num2, 0, num2.Length-1);

            //Sort.InsertionSort(numbers);

            Console.ReadLine();
        }
    }
}
