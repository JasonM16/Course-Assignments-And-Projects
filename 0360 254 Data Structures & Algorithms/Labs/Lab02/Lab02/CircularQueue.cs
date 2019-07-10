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
    public class CircularQueue<T> 
    {
        private int size;
        private T[] items;
        private int head; 
        private int tail; 
        private int N;
        
        
        /******************************************************************************
         CONSTRUCTOR    : Queue

         DESCRIPTION	: 

         INPUT			: Type			: int
                        : Description	: the queue's capacity.                          

         OUTPUT			: Type 			: N/A
                        : Description	: N/A
         ******************************************************************************/
        public CircularQueue(int cpacity)
        {
            items = new T[cpacity];
            head = 0;
            tail = 0;
            size = 0;
            N = cpacity;
        }




        
        /******************************************************************************
        FUNCTION		: Enqueue

        DESCRIPTION		: This method adds a new item to the stack.

        INPUT			: Type			: T - Generic type
                        : Description	: the item to be pushed onto the stack.                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Enqueue(T item)
        {
            if (size == N - 1)
            {
                //throw new StackOverflowException("Error. Queue is full.");
                Console.WriteLine("Error. Queue is full.");
                return;
            }

            items[tail] = item;
            tail = (tail + 1) % N;
            size++;
        }







        /******************************************************************************
        FUNCTION		: Dequeue

        DESCRIPTION		: This method adds a new item to the stack.

        INPUT			: Type			: T - Generic type
                        : Description	: the item to be pushed onto the stack.                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public T Dequeue()
        {
            if (IsEmpty())
            {
                //throw new IndexOutOfRangeException("Error. Queue is empty.");
                Console.WriteLine("Error. Queue is empty.");
                return default(T);
            }

            T item = items[head];
            head = (head + 1) % N;
            size--;
            return item;
        }






        /******************************************************************************
        FUNCTION		: Print

        DESCRIPTION		: This method prints the items of the queue to the console.

        INPUT			: Type			: N/A
                        : Description	: N/A

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Print()
        {
            Console.Write("(");
            for (int i = head, c = 0; i < tail; i++, c++)
            {
                if (c == 0) Console.Write(items[i]);
                else
                {
                    Console.Write("," + items[i]);
                }
            }
                
            Console.WriteLine(")");
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
            return size;
        }






        /******************************************************************************
        FUNCTION		: IsEmpty

        DESCRIPTION		: This method checks if the queue is empty.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: bool
                        : Description	: true, if the queue is empty. False, otherwise.
        ******************************************************************************/
        public bool IsEmpty()
        {
            return size == 0;
        }









        /******************************************************************************
        FUNCTION		: Front

        DESCRIPTION		: This method returns the first item in the queue.

        INPUT			: Type			: N/A
                        : Description	: N/A                      

        OUTPUT			: Type 			: T - Generic type
                        : Description	: the first item in the queue.
        ******************************************************************************/
        public T Front()
        {
            return items[head];
        }
    }
}
