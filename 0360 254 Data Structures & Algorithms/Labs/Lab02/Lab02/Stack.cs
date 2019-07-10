/*
 * PROJECT:     Lab 2 
 * FILE:        Stack.cs
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 25, 2017
 * DESCRIPTION: 
 */



namespace Lab02
{
    public class Stack<T> 
    {
        private readonly SinglyLinkedList<T> stack;


        /******************************************************************************
         CONSTRUCTOR    : Stack

         DESCRIPTION	: The constructor initializes a new stack implemented as a 
                          linked list data structure.

         INPUT			: Type			: N/A
                        : Description	: N/A

         OUTPUT			: Type 			: N/A
                        : Description	: N/A
         ******************************************************************************/
        public Stack()
        {
            stack = new SinglyLinkedList<T>();
        }





        /******************************************************************************
        FUNCTION		: Push

        DESCRIPTION		: This method adds a new item to the stack.

        INPUT			: Type			: T - Generic type
                        : Description	: the item to be pushed onto the stack                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Push(T item)
        {
            stack.AddFirst(item);
        }





        /******************************************************************************
        FUNCTION		: Pop

        DESCRIPTION		: This method removes the top item from the stack.

        INPUT			: Type			: N/A
                        : Description	: N/A                      

        OUTPUT			: Type			: T - Generic type
                        : Description	: returns the removed item from the stack.
        ******************************************************************************/
        public T Pop()
        {
            return stack.RemoveFirst();
        }





        /******************************************************************************
        FUNCTION		: Top

        DESCRIPTION		: This method returns the first item of the stack.

        INPUT			: Type			: N/A
                        : Description	: N/A                       

        OUTPUT			: Type			: T - Generic type
                        : Description	: returns the last item of the stack.
        ******************************************************************************/
        public T Top()
        {
            return stack.GetFirst().Element;
        }





        /******************************************************************************
        FUNCTION		: Size

        DESCRIPTION		: This method returns the size of the stack.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: int
                        : Description	: the size of the stack.
        ******************************************************************************/
        public int Size()
        {
            return stack.Size();
        }





        /******************************************************************************
        FUNCTION		: IsEmpty

        DESCRIPTION		: This method checks if the stack is empty.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: bool
                        : Description	: true, if the stack is empty. False, otherwise.
        ******************************************************************************/
        public bool IsEmpty()
        {
            return stack.Size() == 0;
        }





        /******************************************************************************
        FUNCTION		: Print

        DESCRIPTION		: This method prints the elements of the stack.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Print()
        {
            stack.Print();
        }
    }
}
