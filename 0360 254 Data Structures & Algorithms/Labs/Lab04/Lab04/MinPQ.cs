/*
 * PROJECT          : Lab 4 
 * FILE             : MinPQ.cs
 * AUTHOR           : Jason Choquette 104337378
 * LAST MODIFIED    : Mar. 04, 2017
 * DESCRIPTION      : This class represents a heap-based min. priority queue, 
 *                    where the removeMin method removes the smallest element 
 *                    (key) in the queue. The class takes an array of generic 
 *                    key-value pairs and does a comparison sort on the keys
 *                    (implements IComparable<TKey>) to maintain heap order.
 */


using System;


namespace Lab04
{
    public class MinPq<TKey, TValue> where TKey : IComparable<TKey>
    {
        private KVP<TKey, TValue>[] pq;
        private int size;


        /******************************************************************************
         CONSTRUCTOR    : MinPq

         DESCRIPTION	: MinPq constructor.

         INPUT			: Type			: int
                        : Description	: The initial capcity of the queue.

         OUTPUT			: Type 			: N/A
                        : Description	: N/A
         ******************************************************************************/
        public MinPq(int capacity)
        {
            pq = new KVP<TKey, TValue>[capacity + 1];
            size = 0;
        }





        /******************************************************************************
         CONSTRUCTOR    : MinPq

         DESCRIPTION	: Default MinPq constructor.

         INPUT			: Type			: void
                        : Description	: N/A

         OUTPUT			: Type 			: N/A
                        : Description	: N/A
         ******************************************************************************/
        public MinPq() : this(1) { }





        /**********************************************************************
        METHOD		    : Queue

        DESCRIPTION	    : This method returns the priority queue array.

        INPUT			: Type			: void
                        : Description	: N/A

        OUTPUT			: Type 			: KVP<TKey, TValue>
                        : Description	: Returns the priority queue array.
        ***********************************************************************/
        public KVP<TKey, TValue>[] Queue()
        {
            return pq;
        }





        /**********************************************************************
        METHOD		    : Insert

        DESCRIPTION	    : This method inserts a kvp into the heap.

        INPUT			: Type			: KVP<TKey, TValue>
                        : Description	: The kvp to insert into the heap.

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        public void Insert(KVP<TKey, TValue> item)
        {
            if (size == pq.Length - 1)
                Resize(2 * pq.Length);

            pq[++size] = item;
            UpHeap(size);
        }






        /******************************************************************************
        FUNCTION		: RemoveMin

        DESCRIPTION		: This method removes the smallest element (based on key) from
                          the array.

        INPUT			: Type			: void
				        : Description	: N/A				        
				
        OUTPUT			: Type 			: KVP<TKey, TValue>
				        : Description	: Removes the smallest element (based on key)
                                          from the array.
        ******************************************************************************/
        public KVP<TKey, TValue> RemoveMin()
        {
            if (IsEmpty()) throw new InvalidOperationException("The heap is empty.");

            Exchange(1, size);
            KVP<TKey, TValue> min = pq[size--];
            DownHeap(1);
            pq[size + 1] = null;
            return min;
        }





        /******************************************************************************
        FUNCTION		: Min

        DESCRIPTION		: This method returns (but does not remove) the smallest element
                          (based on key) from the array.

        INPUT			: Type			: KVP<TKey, TValue>
				        : Description	: A generic array of key-value pairs.				        
				
        OUTPUT			: Type 			: void
				        : Description	: N/A
        ******************************************************************************/
        public KVP<TKey, TValue> Min()
        {
            if (IsEmpty()) throw new InvalidOperationException("The heap is empty.");

            return pq[1];
        }





        /******************************************************************************
        FUNCTION		: Size

        DESCRIPTION		: 

        INPUT			: Type			: void
				        : Description	: N/A
				
        OUTPUT			: Type 			: int
				        : Description	: The size of the queue.
        ******************************************************************************/
        public int Size()
        {
            return size;
        }





        /******************************************************************************
        FUNCTION		: IsEmpty

        DESCRIPTION		: 

        INPUT			: Type			: void
				        : Description	: N/A
				
        OUTPUT			: Type 			: bool
				        : Description	: 
        ******************************************************************************/
        public bool IsEmpty()
        {
            return size == 0;
        }





        /******************************************************************************
        FUNCTION		: UpHeap

        DESCRIPTION		: If the heap order is violated because a node’s key becomes 
                        larger than that node’s parent’s key, then we can make progress
                        toward fixing the violation by exchanging the node with its
                        parent. After the exchange, the node is larger than both its 
                        children (one is the old parent, and the other is smaller than
                        the old parent because it was a child of that node) but the
                        node may still be larger than its parent.

                        We can fix that violation in the same way, and so forth, moving
                        up the heap untilwe reach a node with a larger key, or the root.
                        Coding this process is straightforward when you keep in mind 
                        that the parent of the node at position k in a heap is at position
                        k/2. 

                        The loop in swim() preserves the invariant that the only place
                        the heap order could be violated is when the node at position k
                        might be larger than its parent.

                        Therefore, when we get to a place where that node is not larger
                        than its parent, we know that the heap order is satisfied
                        throughout the heap.


        INPUT			: Type			: int
                        : Description	: 		        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ******************************************************************************/
        private void UpHeap(int k)
        {
            while (k > 1 && FirstIsLargerThanSecond(k/2, k))
            {
                Exchange(k, k/2);
                k = k/2;
            }
        }





        /**********************************************************************
        FUNCTION		: DownHeap

        DESCRIPTION		: If the heap order is violated because a node’s key becomes 
                          smaller than one or both of that node’s children’s keys, then
                          we can make progress toward fixing the violation by 
                          exchanging the node with the larger of its two children.
                          This switch may cause a violation at the child; we fix that
                          violation in the same way, and so forth, moving down the heap
                          until we reach a node with both children smaller (or equal), 
                          or the bottom. 

                          The code again follows directly from the fact that the children
                          of the node at position k in a heap are at positions 2k and 2k+1.


        INPUT			: Type			: int
                        : Description	: 

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        private void DownHeap(int k)
        {
            while (2 * k <= size)
            {
                int j = 2 * k;
                if (j < size && FirstIsLargerThanSecond(j, j + 1)) j++;
                if (!FirstIsLargerThanSecond(k, j)) break;
                Exchange(k, j);
                k = j;
            }
        }





        /**********************************************************************
        FUNCTION		: Resize

        DESCRIPTION		: 

        INPUT			: Type			: int
                        : Description	: 			        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        private void Resize(int capacity)
        {
            KVP<TKey, TValue>[] temp = new KVP<TKey, TValue>[capacity];

            for (int i = 1; i <= size; i++)
                temp[i] = pq[i];

            pq = temp;
        }





        /**********************************************************************
        FUNCTION		: Exchange

        DESCRIPTION		: 

        INPUT			: Type			: int
                        : Description	: 	

                        : Type			: int
                        : Description	: 				        

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        private void Exchange(int i, int j)
        {
            KVP<TKey, TValue> temp = pq[i];
            pq[i] = pq[j];
            pq[j] = temp;
        }





        /**********************************************************************
        FUNCTION		: FirstIsLargerThanSecond

        DESCRIPTION		: This method compares two keys to determine if the
                          first key is larger than the second key.

        INPUT			: Type			: int
                         : Description	: first key's index position in the array

                        : Type			: int
                        : Description	: second key's index position in the array

        OUTPUT			: Type 			: bool
                        : Description	: True if the first key is larger. False,
                                          otherwise.
        ***********************************************************************/
        private bool FirstIsLargerThanSecond(int i, int j)
        {
            return pq[i].Key.CompareTo(pq[j].Key) > 0;
        }
    }




    // generic key-value pair
    public class KVP<TKey, TValue>
    {
        public TKey Key { get; set; }
        public TValue Value { get; set; }
    }
}