/*
 * PROJECT          : Lab 4 
 * FILE             : Program.cs
 * AUTHOR           : Jason Choquette 104337378
 * LAST MODIFIED    : Mar. 04, 2017
 * DESCRIPTION      : 
 */

using System;


namespace Lab04
{
    class Program
    {
        static void Main(string[] args)
        {
            #region
            // 5, 9, 6, 15, 12, 7, 20, 16, 25, 14, 19, 11
            //var ik1 = new KVP<int, string> { Key = 14, Value = "Uber" };
            //var ik2 = new KVP<int, string> { Key = 11, Value = "Twitter" };
            //var ik3 = new KVP<int, string> { Key = 5, Value = "Amazon" };
            //var ik4 = new KVP<int, string> { Key = 15, Value = "Microsoft" };
            //var ik5 = new KVP<int, string> { Key = 20, Value = "FaceBook" };
            //var ik6 = new KVP<int, string> { Key = 12, Value = "SpaceX" };
            //var ik7 = new KVP<int, string> { Key = 19, Value = "Tesla" };
            //var ik8 = new KVP<int, string> { Key = 25, Value = "Google" };
            //var ik9 = new KVP<int, string> { Key = 16, Value = "Skype" };
            //var ik10 = new KVP<int, string> { Key = 7, Value = "Oracle" };
            //var ik11 = new KVP<int, string> { Key = 9, Value = "LinkedIn" };
            //var ik12 = new KVP<int, string> { Key = 6, Value = "Apple" };


            //var lk = new MinPq<int, string>();
            //lk.Insert(ik1);
            //lk.Insert(ik2);
            //lk.Insert(ik3);
            //lk.Insert(ik4);
            //lk.Insert(ik5);
            //lk.Insert(ik6);
            //lk.Insert(ik7);
            //lk.Insert(ik8);
            //lk.Insert(ik9);
            //lk.Insert(ik10);
            //lk.Insert(ik11);
            //lk.Insert(ik12);

            //KVP<int, string>[] pqk = { ik1, ik2, ik3, ik4, ik5, ik6, ik7, ik8, ik9, ik10, ik11, ik12 };

            //foreach (var item in pqk)
            //    Console.Write(item.Key + " ");

            //Console.WriteLine();

            //// sort
            //Heap<int, string>.Sort(pqk);
            ////Heap<int, string>.Sort(l.Queue());

            //// sorted queue
            //foreach (var item in pqk)
            //    Console.Write(item.Key + " ");


            //var i1  = new KVP<string, int> { Value = 14, Key = "Uber"      };
            //var i2  = new KVP<string, int> { Value = 11, Key = "Twitter"   };
            //var i3  = new KVP<string, int> { Value = 5,  Key = "Amazon"    };
            //var i4  = new KVP<string, int> { Value = 15, Key = "Microsoft" };
            //var i5  = new KVP<string, int> { Value = 20, Key = "FaceBook"  };
            //var i6  = new KVP<string, int> { Value = 12, Key = "SpaceX"    };
            //var i7  = new KVP<string, int> { Value = 19, Key = "Tesla"     };
            //var i8  = new KVP<string, int> { Value = 25, Key = "Google"    };
            //var i9  = new KVP<string, int> { Value = 16, Key = "Skype"     };
            //var i10 = new KVP<string, int> { Value = 7,  Key = "Oracle"    };
            //var i11 = new KVP<string, int> { Value = 9,  Key = "LinkedIn"  };
            //var i12 = new KVP<string, int> { Value = 6,  Key = "Apple"     };


            //KVP<string, int>[] pq = { i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12 };




            //var l = new Heap<string, int>();
            //l.Insert(i1);
            //l.Insert(i2);
            //l.Insert(i3);
            //l.Insert(i4);
            //l.Insert(i5);
            //l.Insert(i6);
            //l.Insert(i7);
            //l.Insert(i8);
            //l.Insert(i9);
            //l.Insert(i10);
            //l.Insert(i11);
            //l.Insert(i12);


            //// unsorted queue. Heap property: children smaller than parent...
            //foreach (var item in pq)
            //    Console.Write(item.Key + " ");

            //Console.WriteLine();

            //// sort
            //Heap<string, int>.Sort(pq);
            ////Heap<int, string>.Sort(l.Queue());

            //// sorted queue
            //foreach (var item in pq)
            //    Console.Write(item.Key + " ");

            int counter = 0;

            //var A = GenerateRandomKvpArray(size: 100, min: 1, max: 500);


            //Console.WriteLine("Unsorted: \n-----------");
            //foreach (var item in A)
            //{
            //    Console.Write(item.Key.ToString().PadLeft(10));
            //    counter++;
            //    if (counter == 10)
            //    {
            //        Console.WriteLine();
            //        counter = 0;
            //    }
            //}                       

            //Console.WriteLine("\n");

            //// sort
            //Heap<int, string>.HeapSort(A);

            //counter = 0;
            //Console.WriteLine("Sorted: \n-----------");
            //// sorted queue
            //foreach (var item in A)
            //{
            //    Console.Write(item.Key.ToString().PadLeft(10));
            //    counter++;
            //    if(counter == 10)
            //    {
            //        Console.WriteLine();
            //        counter = 0;
            //    }
            //}

#endregion
            
            SortTests.RunTests();
            SortTests.PrintResults();
                
            Console.ReadLine();
        }       
    }
}
