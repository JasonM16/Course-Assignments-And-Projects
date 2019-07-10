using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;


namespace Lab02
{
    public static class Tests
    {
        public static void GetQueueInputFromUser()
        {
            char delim = ' ';
            Queue<int?> q = new Queue<int?>();

            Console.Write("Enter print jobs: ");
            string input = Console.ReadLine();
           
            string[] printJobs = input.Split(delim);
            
            foreach (string job in printJobs)
                q.Enqueue(int.Parse(job));
            
            Console.Write("Current printer spooler: ");
            q.Print();

            Console.WriteLine("\nQueue empty: {0}\n", q.IsEmpty());

            int size = q.Size();
            for (int i = 0; i < size; i++)
                Console.WriteLine("Printing job...{0}", q.Dequeue());

            Console.WriteLine("\nQueue empty: {0}", q.IsEmpty());
        }


        public static void RunBracketProgram()
        {
            // regex for digits, operators and brackets
            string regex = @"^[\d\+\/\*\.\- \(\)\{\}\[\]]*$";

            // list to hold testing expressions
            var expressions = new List<string>();

            // expressions to test
            string a = "(9*[3*{[(3+3)/5]*7}])";
            string b = "{3*(2+[3-[4/[6/9]]]})";
            string c = "((3*(9-(4*(6-5))))";
            string d = "{2-{3*{6/[[[(((9-0)))]]]}}/7}";
            string e = "{2a-{3*{6/[[[(((9-0)))]]]}}/7}";

            // add the expressions to the list
            expressions.Add(a);
            expressions.Add(b);
            expressions.Add(c);
            expressions.Add(d);
            //expressions.Add(e);
            //expressions.Add("");
            //expressions.Add("95");
            //expressions.Add(")]");
            //expressions.Add("98*()+{]");

            // iterate over all of the expressions
            foreach (var expression in expressions)
            {
                // check that all the expressions are valid using a regex
                if (!AllValidCharacters(expression, regex))
                {
                    Console.WriteLine("Invalid character(s) in expression {0}", expression);
                    continue;
                }

                Console.Write("Brackets ");
                Console.Write(Brackets.BracketMatch(expression) ? "match " : "do not match ");
                Console.WriteLine("for expression {0}.", expression);
            }
        }



        /******************************************************************************
        FUNCTION		: AllValidCharacters

        DESCRIPTION		: This method evaluates all the characters of a string and 
                        determines if the characters are all valid.

        INPUT			: Type			: string
                        : Description	: the string to be matched against the regex
                        : Type			: string
                        : Description	: the regex expression

        OUTPUT			: Type 			: bool
                        : Description	: true if all the characters are valid

        Analysis        : O(n)
        Source          : http://stackoverflow.com/questions/4378455/what-is-the-complexity-of-regular-expression
        ******************************************************************************/
        private static bool AllValidCharacters(string v, string regex)
        {
            return Regex.IsMatch(v, regex);
        }




        #region
        public static void RunSinglyLinkedListProgram() { }

        //public static void RunCircularQueue()
        //{
        //    CircularQueue<int?> q = new CircularQueue<int?>(10);

        //    q.Enqueue(5);
        //    q.Print();

        //    q.Enqueue(3);
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();

        //    q.Enqueue(7);
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();

        //    q.Front();
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();

        //    q.Dequeue();
        //    q.Print(); // error

        //    q.IsEmpty(); // true

        //    q.Enqueue(9);
        //    q.Print();

        //    q.Enqueue(7);
        //    q.Print();

        //    q.Enqueue(3);
        //    q.Print();

        //    q.Enqueue(5);
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();
        //}

        //public static void RunPrinterQueueProgram()
        //{
        //    Queue<int?> q = new Queue<int?>();

        //    //for (int i = 0; i <= 10; i++)
        //    //{
        //    //    q.Enqueue(i);
        //    //}

        //    //q.Print();



        //    q.Enqueue(5);
        //    q.Print();

        //    q.Enqueue(3);
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();

        //    q.Enqueue(7);
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();

        //    //q.Front();
        //    //q.Print();

        //    q.Dequeue();
        //    q.Print();

        //    //q.Dequeue();
        //    //q.Print(); // error

        //    //q.IsEmpty(); // true

        //    q.Enqueue(9);
        //    q.Print();

        //    q.Enqueue(7);
        //    q.Print();

        //    q.Enqueue(3);
        //    q.Print();

        //    q.Enqueue(5);
        //    q.Print();

        //    q.Dequeue();
        //    q.Print();
        //}

        //public static void RunCitiesProgram()
        //{
        //    SinglyLinkedList<string> cities = new SinglyLinkedList<string>();

        //    cities.AddFirst("Toronto");
        //    cities.AddFirst("Seattle");
        //    cities.AddFirst("Rome");

        //    cities.Print();
        //    Console.WriteLine("Size: " + cities.Size());


        //    Console.WriteLine("\nAdd Baltimore first\n");
        //    cities.AddFirst("Baltimore");
        //    cities.Print();
        //    Console.WriteLine("Size: " + cities.Size());


        //    Console.WriteLine("\nAdd New York last\n");
        //    cities.AddLast("New York");
        //    cities.Print();
        //    Console.WriteLine("Size: " + cities.Size());


        //    Console.WriteLine("\nRemove Baltimore\n");
        //    cities.RemoveFirst();
        //    cities.Print();
        //    Console.WriteLine("Size: " + cities.Size());


        //    Console.WriteLine("\nRemove New York\n");
        //    cities.RemoveLast();
        //    cities.Print();
        //    Console.WriteLine("Size: " + cities.Size());
        //}

        #endregion
    }
}
