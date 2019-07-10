/*
* ASSIGNMENT	: Lab 1
* FILE	 		: Stack.cs
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: January 15/17		 
*/


using System;


namespace Lab1
{
    public class Stack<T>  
    {
        int size = 0;
        T[] items;
        
        public Stack(int s)
        {            
            items = new T[s];            
        }
                     

        string empty = "Stack is empty!";


        /******************************************************************************
        FUNCTION		: Push

        DESCRIPTION		: This method adds a new item to the stack.

        INPUT			: Type			: T - Generic Parameter
                        : Description	: the item to be pushed onto the stack                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Push(T item)
        {
            if (size == items.Length)
            {
                Console.WriteLine("Error. Stack is full");
            }
            else
            {
                items[size] = item;
                size++;
            }                    
        }





        /******************************************************************************
        FUNCTION		: Pop

        DESCRIPTION		: This method removes the top item from the stack.

        INPUT			: Type			: N/A
                        : Description	: N/A                      

        OUTPUT			: Type			: T - Generic Parameter
                        : Description	: returns the removed item from the stack
        ******************************************************************************/
        public T Pop()
        {
            if (size == 0) throw new InvalidOperationException(empty);
            size--;            
            return items[size];
        }





        /******************************************************************************
        FUNCTION		: Top

        DESCRIPTION		: This method returns the item on top of the stack

        INPUT			: Type			: N/A
                        : Description	: N/A                       

        OUTPUT			: Type			: T - Generic Parameter
                        : Description	: returns the last item of the stack
        ******************************************************************************/
        public T Top()
        {
            if (size == 0) throw new InvalidOperationException(empty);
            return items[size - 1];
        }





        /******************************************************************************
        FUNCTION		: Size

        DESCRIPTION		: This method returns the size of the stack

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: int
                        : Description	: the size of the stack
        ******************************************************************************/
        public int Size()
        {
            return size;
        }





        /******************************************************************************
        FUNCTION		: IsEmpty

        DESCRIPTION		: This method checks if the stack is empty

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: bool
                        : Description	: true, if the stack is empty. false otherwise
        ******************************************************************************/
        public bool IsEmpty()
        {
            return size == 0;
        }        
    }
}


