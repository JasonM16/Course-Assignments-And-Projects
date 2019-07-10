using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;


namespace A3Test
{
    public static class Extensions
    {
        public static Stack<string> ToStack(this IEnumerable<string> elems)
        {
            Stack<string> newStack = new Stack<string>();
            foreach (var elem in elems)
            {
                newStack.Push(elem);
            }

            return newStack;
        }

    }
}
