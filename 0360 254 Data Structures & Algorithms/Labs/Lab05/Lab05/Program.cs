/*
 * PROJECT          : Lab 5 
 * FILE             : Program.cs
 * AUTHOR           : Jason Choquette 104337378
 * LAST MODIFIED    : Mar. 24, 2017
 * DESCRIPTION      : 
 */


using System;
using System.Diagnostics;

namespace Lab05
{
    class Program
    {
        static void Main(string[] args)
        {
            #region  TASK 4
            BinarySearchTree bst = new BinarySearchTree();
            // basically a linked-list...
            Console.WriteLine("Building BST...\n");
            bst.Insert(1);
            bst.Insert(2);
            bst.Insert(2);
            bst.Insert(3);
            bst.Insert(4);
            bst.Insert(5);
            bst.Insert(6);
            bst.Insert(7);
            bst.Insert(8);
            bst.Insert(9);
            bst.Insert(10);
            bst.Insert(11);
            bst.Insert(12);
            bst.Insert(13);
            bst.Insert(14);
            bst.Insert(15);

            bst.InOrderTraversal();
            Console.WriteLine("\n");

            #endregion


            #region TASK 5
            // stopwatch
            Stopwatch sw1 = new Stopwatch();
            sw1.Start();
            for (int i = 0; i < 100_000; i++)
            {
                bst.Find(1);
                bst.Find(15);
            }
            sw1.Stop();
            Console.WriteLine("Operations Find(1) and Find (15) took {0} miliseconds to complete", sw1.ElapsedMilliseconds);

            // end stopwatch
            #endregion


            #region TASK 6
            Console.WriteLine("\nCurrent BST: ");
            bst.InOrderTraversal();

            Console.WriteLine("\n\nRemoving 5 from BST. Updated Tree: ");
            bst.Remove(5);            
            bst.InOrderTraversal();

            Console.WriteLine("\n\nRemoving 15 from BST. Updated Tree: ");
            bst.Remove(15);                   
            bst.InOrderTraversal();

            Console.WriteLine("\n\nRemoving 1 from BST. Updated Tree: ");
            bst.Remove(1);           
            bst.InOrderTraversal();
            
            Console.WriteLine("\n\nInserting 2 in BST. Updated Tree: ");
            bst.Insert(2);            
            bst.InOrderTraversal();            
            #endregion


            #region TASK 7
            BinarySearchTree bst1 = new BinarySearchTree();
            bst1.Insert(8);
            bst1.Insert(4);
            bst1.Insert(12);
            bst1.Insert(2);
            bst1.Insert(6);
            bst1.Insert(10);
            bst1.Insert(14);
            bst1.Insert(1);
            bst1.Insert(3);
            bst1.Insert(5);
            bst1.Insert(7);
            bst1.Insert(9);
            bst1.Insert(11);
            bst1.Insert(13);
            bst1.Insert(15);
            Console.WriteLine("\n\nBuilding a new BST...\n");
            Console.WriteLine("Current new BST\n");
            bst1.InOrderTraversal();
            Console.WriteLine("\n");
            #endregion


            #region TASK 8
            Stopwatch sw2 = new Stopwatch();
            sw2.Start();
            for (int i = 0; i < 100_000; i++)
            {
                bst1.Find(1);
                bst1.Find(15);
            }
            sw2.Stop();
            Console.WriteLine("Operations Find(1) and Find (15) took {0} miliseconds to complete", sw2.ElapsedMilliseconds);
            #endregion


            #region TASK 10
            Console.WriteLine("\n\nRemoving 8 from new BST. Updated Tree: ");
            bst1.Remove(8);           
            bst1.InOrderTraversal();
            Console.WriteLine("\n");
            #endregion            


            Console.ReadLine();
        }
    }
}
