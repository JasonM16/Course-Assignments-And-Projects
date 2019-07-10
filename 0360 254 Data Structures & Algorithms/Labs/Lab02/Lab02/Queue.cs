/*
 * PROJECT:     Lab 2 
 * FILE:        Queue.cs
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 25, 2017
 * DESCRIPTION: 
 */



using System;

namespace Lab02
{
    public class Queue<T>
    {
        private readonly SinglyLinkedList<T> queue;


        /******************************************************************************
        CONSTRUCTOR		: Queue

        DESCRIPTION		: The constructor initializes a new queue implemented as a 
                          linked list  data structure.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: N/A
                        : Description	: N/A
        ******************************************************************************/
        public Queue()
        {
            queue = new SinglyLinkedList<T>();
        }





        /******************************************************************************
        FUNCTION		: Enqueue

        DESCRIPTION		: This method adds an element to the end of the queue.

        INPUT			: Type			: T
                        : Description	: the item to add to the end of th queue.                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Enqueue(T item)
        {
            queue.AddLast(item);
        }





        /******************************************************************************
        FUNCTION		: Dequeue

        DESCRIPTION		: This method removes the first element from the queue

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: Y
                        : Description	: the removed element.
        ******************************************************************************/
        public T Dequeue()
        {
            return queue.RemoveFirst();
        }





        /******************************************************************************
        FUNCTION		: Front

        DESCRIPTION		: This method returns the first element of the queue

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: T
                        : Description	: the first element of the queue.
        ******************************************************************************/
        public T Front()
        {
            return queue.GetFirst().Element;
        }

        



        /******************************************************************************
        FUNCTION		: Size

        DESCRIPTION		: This method returns the size of the queue.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: int
                        : Description	: the size of the queue.
        ******************************************************************************/
        public int Size()
        {
            return queue.Size();
        }





        /******************************************************************************
        FUNCTION		: IsEmpty

        DESCRIPTION		: This method checks if the queue is empty

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: bool
                        : Description	: true, if the queue is empty. False, otherwise.
        ******************************************************************************/
        public bool IsEmpty()
        {
            return queue.IsEmpty();
        }




        
        /******************************************************************************
        FUNCTION		: Print

        DESCRIPTION		: This method prints the elements of the queue.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Print()
        {
            Node<T> current = queue.GetFirst();
            Console.Write("(");
            int count = 0;

            while (current != null)
            {
                if (count == 0)
                    Console.Write(current.Element);
                
                else
                    Console.Write("," + current.Element);

                count++;
                current = current.Next;
            }

            Console.WriteLine(")");
        }
    }
}
