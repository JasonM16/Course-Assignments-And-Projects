/*
 * PROJECT:     Lab 2 
 * FILE:        SinglyLinkedList.cs
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 25, 2017
 * DESCRIPTION: 
 */

using System;


namespace Lab02
{
    public class SinglyLinkedList<T> 
    {
        private Node<T> head;
        private Node<T> tail;
        private int     size;
        

        /******************************************************************************
         CONSTRUCTOR    : SinglyLinkedList

         DESCRIPTION	: The constructor initializes the head and tail nodes.

         INPUT			: Type			: N/A
                        : Description	: N/A

         OUTPUT			: Type 			: N/A
                        : Description	: N/A
         ******************************************************************************/
        public SinglyLinkedList()
        {
            head = new Node<T> {Next = null};
            tail = new Node<T> {Next = null};
            size = 0;
        }





        /******************************************************************************
        FUNCTION		: AddFirst

        DESCRIPTION		: This method adds a new item to the list.

        INPUT			: Type			: T - Generic type
                        : Description	: the item to be added into the head of the list.                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void AddFirst(T item)
        {
            Node<T> first = new Node<T>
            {
                Element = item,
                Next    = head
            };

            head = first;
            size++;
            if (size == 1) tail = head;
        }





        /******************************************************************************
        FUNCTION		: RemoveFirst

        DESCRIPTION		: This method removes the first item from the list.

        INPUT			: Type			: N/A
                        : Description	: N/A                      

        OUTPUT			: Type			: T - Generic type
                        : Description	: returns the first item removed from the list.
        ******************************************************************************/
        public T RemoveFirst()
        {
            if (Size() == 0) throw new InvalidOperationException();     
            
            Node<T> temp = head;
            head = head.Next;
            temp.Next = null;
            size--;
            return temp.Element;
        }





        /******************************************************************************
        FUNCTION		: AddLast

        DESCRIPTION		: This method adds a new item to the end of the list.

        INPUT			: Type			: T - Generic type
                        : Description	: the item to be added to the end of the list                        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void AddLast(T element)
        {
            if (Size() == 0)
                AddFirst(element);
            else
            {
                Node<T> last = new Node<T> { Element = element, Next = null };
                tail.Next = last;
                tail = last;
                size++;
            }
        }





        /******************************************************************************
        FUNCTION		: RemoveLast

        DESCRIPTION		: This method removes the last element of the list.

        INPUT			: Type			: N/A
                        : Description	: N/A                      

        OUTPUT			: Type 			: Node<T>
                        : Description	: returns the new tail of the list.
        ******************************************************************************/
        public Node<T> RemoveLast()
        {
            Node<T> current = head;
            while (current != null)
            {
                //what if only one element??
                if (current.Next == null)
                {
                    RemoveFirst();
                    return current;
                }

                if (current.Next.Next == null) // 2nd last element will become last. O(n-2) == O(n)
                {
                    current.Next = null;
                    break;
                }

                current = current.Next;
            }

            tail = current;
            size--;

            return tail;
        }





        /******************************************************************************
        FUNCTION		: GetFirst

        DESCRIPTION		: This method returns the first element of the linked list.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: Node<T>
                        : Description	: returns the head of the list.
        ******************************************************************************/
        public Node<T> GetFirst()
        {
            return head;
        }





        /******************************************************************************
        FUNCTION		: GetLast

        DESCRIPTION		: This method returns the last element (tail) of the list.

        INPUT			: Type			: N/A
                        : Description	: N/A                

        OUTPUT			: Type 			: Node<T>
                        : Description	: the tail of the list.
        ******************************************************************************/
        public Node<T> GetLast()
        {
            return tail;
        }



        

        /******************************************************************************
        FUNCTION		: Size

        DESCRIPTION		: This method returns the size of the list.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: int
                        : Description	: the size of the list.
        ******************************************************************************/
        public int Size()
        {
            return size;
        }




        
        /******************************************************************************
        FUNCTION		: IsEmpty

        DESCRIPTION		: This method checks if the list is empty.

        INPUT			: Type			: N/A
                        : Description	: N/A                        

        OUTPUT			: Type 			: bool
                        : Description	: true, if the list is empty. False, otherwise.
        ******************************************************************************/
        public bool IsEmpty()
        {
            return size == 0;
        }



        

        /******************************************************************************
        FUNCTION		: Print

        DESCRIPTION		: This method prints the items of the list to the console.

        INPUT			: Type			: N/A
                        : Description	: N/A

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        public void Print()
        {
            Node<T> current = head;
            while (current != null)
            {
                Console.WriteLine(current.Element);
                current = current.Next;
            }
        }
    }


    // simple class to represent a single node in a linked list
    public class Node<T>
    {
        public Node<T> Next { get; set; }
        public T Element { get; set; }
    }
}
