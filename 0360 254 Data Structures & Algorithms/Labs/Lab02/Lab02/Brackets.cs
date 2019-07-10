/*
 * PROJECT:     Lab 2 
 * FILE:        Brackets.cs
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 25, 2017
 * DESCRIPTION: 
 */


namespace Lab02
{
    public static class Brackets
    {
        /******************************************************************************
        FUNCTION		: BracketMatch

        DESCRIPTION		: This method parses and analyzes the brackets of an expression 
                          of a string to determine if they all match.

        INPUT			: Type			: string
				        : Description	: the string to be parsed				        
				
        OUTPUT			: Type 			: bool
				        : Description	: true if the brackets all match, false otherwise
        ******************************************************************************/
        public static bool BracketMatch(string s)
        {
            var brackets = new Stack<char>();

            // iterate over the string
            // compares each character in the string - O(n)
            foreach (char c in s)
            {
                // opening brackets
                if (c.Equals('(') || c.Equals('[') || c.Equals('{')) brackets.Push(c);
                // closing brackets
                else if (c.Equals(')') || c.Equals(']') || c.Equals('}'))
                {
                    if (brackets.Size() == 0)
                        return false;
                    if (!IsMatchingType(brackets.Pop(), c))
                        return false;
                }
            }

            return brackets.Size() == 0;
        }





        /******************************************************************************
        FUNCTION		: IsMatchingType

        DESCRIPTION		: This method compares two brackets and determines if they
                          match as opening and closing bracket groups.

        INPUT			: Type			: char
                        : Description	: the first bracket to be compared
                        : Type			: char
                        : Description	: the second bracket to be compared

        OUTPUT			: Type 			: bool
                        : Description	: true if brackets matched. false otherwise
        ******************************************************************************/
        private static bool IsMatchingType(char open, char close)
        {
            if (open == '(' && close == ')')
                return true;
            if (open == '[' && close == ']')
                return true;
            if (open == '{' && close == '}')
                return true;
            else
                return false;
        }

    } // end class Brackets
}
