/*
* ASSIGNMENT	: Lab 1
* FILE	 		: Program.cs
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: January 15/17
* DESCRIPTION	: This program evaluates mathematical expressions for
*                 matching brackets for order of evaluation according
*                 to BEDMAS.			
*                 
* Task 3        : Assuming an input string of size n: 
* 
*                 (a) what is the worst-case time that your algorithm
*                 takes to decide whether or not the string is correct
*                 (balanced) or incorrect (unbalanced)?
*                 
*                 (b) Why? Give your answers in terms of the O-notation.                               	  
*/


using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;



namespace Lab1
{
    class Program
    {
        static void Main(string[] args)
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
            //expressions.Add(b);
            //expressions.Add(c);
            //expressions.Add(d);
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

                if (Brackets.BracketMatch(expression))
                    Console.Write("match ");

                else
                    Console.Write("do not match ");

                Console.WriteLine("for expression {0}.", expression);
            }           

            Console.ReadLine();
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
    }
}
