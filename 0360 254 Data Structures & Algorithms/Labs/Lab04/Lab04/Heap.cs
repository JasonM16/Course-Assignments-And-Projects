/*
 * PROJECT          : Lab 4 
 * FILE             : Heap.cs
 * AUTHOR           : Jason Choquette 104337378
 * LAST MODIFIED    : Mar. 03, 2017
 * DESCRIPTION      : This class implements the heap-sort algorithm on an 
 *                    array of key-value pairs. The sort is based on a 
 *                    generic key and allows for 'natural' sorting on
 *                    primitive types. (Any non-primitive types will have to 
 *                    implement the ICompare<T> interface.)
 *                    
 * DESCRIPTION      : This class represents a heap-based min. priority queue, 
 *                    where the removeMin method removes the smallest element 
 *                    (key) in the queue. The class takes an array of generic 
 *                    key-value pairs and does a comparison sort on the keys
 *                    (implements IComparable<TKey>) to maintain heap order.
 */


using System;


namespace Lab04
{
    public class Heap<TKey, TValue> where TKey : IComparable<TKey>
    {       

        /******************************************************************************
        FUNCTION		: Sort

        DESCRIPTION		: Rearranges the array in ascending order, using the natural order.                        

                        HEAPSORT:: We can use any priority queue to develop a sorting method. 
                        
                        We insert all the items to be sorted into a minimum-oriented priority queue, then repeatedly use
                        remove the minimum to remove them all in order. 
            
                        Using a priority queue represented as an unordered array in this way corresponds to doing a selection sort;

                        using an ordered array corresponds to doing an insertion sort.
            
                        What sorting method do we get if we use a heap? An entirely different one! 
            
                        Next, we use the heap to develop a classic elegant sorting algorithm known as heapsort.

                        Heapsort breaks into two phases:
                        --------------------------------
                        1) heap construction, where we reorganize the original array into a heap, and;
                        
                        2) the sortdown, where we pull the items out of the heap in decreasing order to build the sorted result.
                        

                        HEAP CONSTRUCTION.
                        *************************************************************************************************************************************
                        How difficult is the process of building a heap from N given items?

                        Certainly we can accomplish this task in time proportional to N log N, by proceeding from left to right through the array,
                        using UpHeap() to ensure that the items to the left of the scanning pointer make up a heap-ordered complete tree, 
                        like successive priority queue insertions.
                        
                        A clever method that is much more efficient is to proceed from right to left, using DownHeap() to make subheaps as we go.
                        
                        Every position in the array is the root of a small subheap; DownHeap() works for such subheaps, as well. If the two children of a
                        node are heaps, then calling DownHeap() on that node makes the subtree rooted at the parent a heap.
                        
                        This process establishes the heap order inductively.
            
                        ****The scan starts halfway back through the array because we can skip the subheaps of size 1.
                        The scan ends at position 1, when we finish building the heap with one call to DownHeap().****
                        
                        As the first phase of a sort, heap construction is a bit counterintuitive, because its goal is to produce a
                        heap-ordered result, which has the largest item first in the array (and other larger items near the beginning),
                        not at the end, where it is destined to finish.

                        SORTDOWN.
                        ***************************************************************************************************************************************
                        Most of the work during heapsort is done during the second phase, where we remove the largest remaining item from the
                        heap and put it into the array position vacated as the heap shrinks.
                        
                        This process is a bit like selection sort (taking the items in decreasing order instead of in increasing order), but it
                        uses many fewer compares because the heap provides a much more efficient way to find the largest item in the unsorted part
                        of the array.

                        Although the loops in this program seem to do different tasks (the first constructs the heap, and the second destroys the heap for the
                        sortdown), they are both built around the DownHeap() method.      
                                 
                        


        INPUT			: Type			: KVP<TKey, TValue>[]
				        : Description	: A generic array of key-value pairs.				        
				
        OUTPUT			: Type 			: void
				        : Description	: N/A
        ******************************************************************************/
        public static void HeapSort(KVP<TKey, TValue>[] pq)
        {
            int n = pq.Length;

            for (int k = n / 2; k >= 1; k--)
                DownHeap(pq, k, n);

            while (n > 1)
            {
                Exchange(pq, 1, n--);
                DownHeap(pq, 1, n);
            }
        }





        /******************************************************************************
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
                          

        INPUT			: Type			: KVP<TKey, TValue>[]
				        : Description	: A generic array of key-value pairs.	
                        
                        : Type			: int
				        : Description	: first key's index position in the array

                        : Type			: int
				        : Description	: The length of the array
				
        OUTPUT			: Type 			: void
				        : Description	: N/A
        ******************************************************************************/
        private static void DownHeap(KVP<TKey, TValue>[] pq, int k, int n)
        {
            while (2 * k <= n)
            {
                int j = 2 * k;
                if (j < n && FirstIsSmallerThanSecond(pq, j, j + 1)) j++;
                if (!FirstIsSmallerThanSecond(pq, k, j)) break;
                Exchange(pq, k, j);
                k = j;
            }
        }





        /******************************************************************************
        FUNCTION		: FirstIsSmallerThanSecond

        DESCRIPTION		: This method compares two keys to determine if the
                          first key is smaller than the second key.

        INPUT			: Type			: KVP<TKey, TValue>[]
				        : Description	: A generic array of key-value pairs.
                        
                        : Type			: int
				        : Description	: first key's index position in the array

                        : Type			: int
				        : Description	: second key's index position in the array
				
        OUTPUT			: Type 			: bool
				        : Description	: True if the first key is smaller. False,
                                          otherwise.
        ******************************************************************************/
        private static bool FirstIsSmallerThanSecond(KVP<TKey, TValue>[] pq, int i, int j)
        {
            return pq[i-1].Key.CompareTo(pq[j-1].Key) < 0;
        }





        /******************************************************************************
        FUNCTION		: Exchange

        DESCRIPTION		: This method swaps keys (positions) in the array.

        INPUT			: Type			: KVP<TKey, TValue>[]
				        : Description	: A generic array of key-value pairs.		
                        
                        : Type			: int
				        : Description	: Index position of first element to swap.

                        : Type			: int
				        : Description	: Index position of second element to swap.
				
        OUTPUT			: Type 			: void
				        : Description	: N/A
        ******************************************************************************/
        private static void Exchange(KVP<TKey, TValue>[] pq, int i, int j)
        {
            KVP<TKey, TValue> temp = pq[i-1];
            pq[i-1] = pq[j-1];
            pq[j-1] = temp;
        }        
    }    
}
