/*
 * PROJECT          : Lab 5
 * FILE             : BinarySearchTree.cs
 * AUTHOR           : Jason Choquette 104337378
 * LAST MODIFIED    : Mar. 21, 2017
 * DESCRIPTION      : 
 */


using System;


namespace Lab05
{
    class BinarySearchTree
    {
        private Node root; 


        /**********************************************************************
        METHOD		    : Size

        DESCRIPTION	    : Returns the number of keys in this BST.

        INPUT			: Type			: void
                        : Description	: N/A

        OUTPUT			: Type 			: int
                        : Description	: Returns the size of the BST.
        ***********************************************************************/
        public int Size()
        {
            return Size(root);
        }





        /**********************************************************************
        METHOD		    : Size

        DESCRIPTION	    : Return number of keys in BST rooted at n.

        INPUT			: Type			: Node
                        : Description	: 

        OUTPUT			: Type 			: int
                        : Description	: Returns the size of the BST.
        ***********************************************************************/
        private int Size(Node n)
        {
            return n?.Size ?? 0;
        }





        /**********************************************************************
        METHOD		    : IsEmpty

        DESCRIPTION	    : This method tests if the BST is empty.

        INPUT			: Type			: void
                        : Description	: N/A

        OUTPUT			: Type 			: bool
                        : Description	: True if the BST is empty. 
                                          False, otherwise
        ***********************************************************************/
        public bool IsEmpty()
        {
            return Size() == 0;
        }




        
        /**********************************************************************
        METHOD		    : Contains

        DESCRIPTION	    : This method tests if the BST contains a search key.

        INPUT			: Type			: int
                        : Description	: The key to search for.

        OUTPUT			: Type 			: bool
                        : Description	: True if the BST contains the key.
                                          False, otherwise
        ***********************************************************************/
        public bool Contains(int key)
        {
            return Find(key) != null;
        }





        /**********************************************************************
        METHOD		    : Find

        DESCRIPTION	    : Returns the Node associated with the given key.

        INPUT			: Type			: int
                        : Description	: The key to find.

        OUTPUT			: Type 			: Node
                        : Description	: Returns the node of the key or null
                                          if the key was not found.
        ***********************************************************************/
        public Node Find(int key)
        {
            return TreeSearch(root, key);
        }





        /**********************************************************************
        METHOD		    : TreeSearch

        DESCRIPTION	    : This method uses a binary search to find a key.

        INPUT			: Type			: Node
                        : Description	: The Node rooted at n.

                        : Type			: int
                        : Description	: The key to search for.

        OUTPUT			: Type 			: Node
                        : Description	: The Node of the associated key.
        ***********************************************************************/
        private Node TreeSearch(Node n, int key)
        {
            if (key < n.Key) return TreeSearch(n.Left,  key);
            if (key > n.Key) return TreeSearch(n.Right, key);
            return n;
        }





        /**********************************************************************
        METHOD		    : Insert

        DESCRIPTION	    : This method inserts the specified key into the list.                          

        INPUT			: Type			: int
                        : Description	: The key to insert into the list.

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        public void Insert(int key)
        {
            root = Insert(root, key);
        }





        /**********************************************************************
        METHOD		    : Insert

        DESCRIPTION	    : This method inserts the specified key into the symbol
                          table, overwriting the old value with the new value 
                          if the symbol table already contains the specified key.
                          Deletes the specified key (and its associated value)
                          from this symbol table if the specified value is null.

        INPUT			: Type			: Node
                        : Description	: Use this Node's key to compare to the
                                          given key.

                        : Type			: int
                        : Description	: The key to be inserted.

        OUTPUT			: Type 			: Node
                        : Description	: Returns the new Node of the key.
        ***********************************************************************/
        private Node Insert(Node n, int key)
        {
            if (n == null) return new Node(key, 1);

            if (key < n.Key) n.Left  = Insert(n.Left,  key);
            if (key > n.Key) n.Right = Insert(n.Right, key);            
            n.Size = 1 + Size(n.Left) + Size(n.Right);
            return n;
        }






        /**********************************************************************
        METHOD		    : Remove

        DESCRIPTION	    : This method removes the specified key from this 
                          list (if the key is in this symbol table).  

        INPUT			: Type			: int
                        : Description	: The key to be removed.

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        public void Remove(int key)
        {
            // easier to update tree with this reference and recursively calling
            // remove on the left/right subtree (based on key comprisons of these
            // nodes)
            root = Remove(root, key);
        }





        /**********************************************************************
        METHOD		    : Remove

        DESCRIPTION	    : This method removes the specified key from this 
                          list (if the key is in this symbol table).  

        INPUT			: Type			: Node
                        : Description	: The current Tree node

            			: Type			: int
                        : Description	: The search key                        

        OUTPUT			: Type 			: Node
                        : Description	: Returns the replacement node of the 
                                          which was removed
        ***********************************************************************/       
        private Node Remove(Node n, int key)
        {
            // base case
            if (n == null) return null;

            // if key is less, do a recursive search on the left child
            if (key < n.Key)
            {
                n.Left = Remove(n.Left, key);
            }

            // conversely, if key is greater, do a recursive search on the right child
            if (key > n.Key)
            {
                n.Right = Remove(n.Right, key);
            }

            // we found the key!            
            // Now, we are left with two links, but have a place in the parent node for only one of them.
            // Delete node n by replacing it with its successor.            
            else
            {
                // only one link. return non-null child as new node to replace parent.
                if (n.Right == null) return n.Left;
                if (n.Left  == null) return n.Right;

                // Both children are non-null...
                // Because n has a right child, its successor is the node with the smallest key in its right subtree. 
                // The replacement preserves order in the tree because there are no keys between n.key and the successor’s key. 

                // save link to node to be deleted
                Node t = n;

                // Node n's successor will be right child's subtree with the smallest key
                n = Min(t.Right);

                // Set the right link of n (which is supposed to point to the BST containing all the keys larger
                // than n.key) to deleteMin(t.right), the link to the BST containing all the keys that are larger
                // than n.key after the deletion.
                n.Right = RemoveMin(t.Right);

                // Set the left link of n (which was null) to t.left (all the keys that are less than both the deleted
                // key and its successor).
                n.Left = t.Left;
            }
            
            return n;
        }





        /**********************************************************************
        METHOD		    : RemoveMin

        DESCRIPTION	    : This method removes the smallest key in the list.

        INPUT			: Type			: void
                        : Description	: N/A

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        public void RemoveMin()
        {
            if (IsEmpty()) throw new Exception("BST is empty.");
            root = RemoveMin(root);
        }





        /**********************************************************************
        METHOD		    : RemoveMin

        DESCRIPTION	    : This method removes the smallest key and associated
                          value from the list.

        INPUT			: Type			: Node
                        : Description	: The current Node whose key we are 
                                          comparing.                                          

        OUTPUT			: Type 			: Node
                        : Description	: Returns the Node with the smallest key.
        ***********************************************************************/
        private Node RemoveMin(Node n)
        {
            if (n.Left == null) return n.Right;
            n.Left = RemoveMin(n.Left);
            n.Size = Size(n.Left) + Size(n.Right) + 1;
            return n;
        }





        /**********************************************************************
        METHOD		    : Min

        DESCRIPTION	    : This method returns the smallest key.

        INPUT			: Type			: void
                        : Description	: N/A

        OUTPUT			: Type 			: int
                        : Description	: Returns the smallest key.
        ***********************************************************************/
        public int Min()
        {
            if (IsEmpty()) throw new Exception("BST is empty.");
            return Min(root).Key;
        }





        /**********************************************************************
        METHOD		    : Min

        DESCRIPTION	    : This method returns the smallest key.

        INPUT			: Type			: Node
                        : Description	: The current Node whose key we are 
                                          comparing.    

        OUTPUT			: Type 			: Node
                        : Description	: Returns the Node with the smallest key.
        ***********************************************************************/
        private Node Min(Node n)
        {
            return n.Left == null ? n : Min(n.Left);
        }




        
        /**********************************************************************
        METHOD		    : InOrderTraversal

        DESCRIPTION	    : This method traverses the BST beginning at the root.

        INPUT			: Type			: void
                        : Description	: N/A

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        public void InOrderTraversal()
        {
            InOrderTraversal(root);            
        }




        
        /**********************************************************************
        METHOD		    : InOrderTraversal

        DESCRIPTION	    : This method performs an in-order traversal by recursively
                          searching the left and right nodes of node n and prints
                          each key.
                          Since the traversal is in-order, the keys will be 
                          displayed in ascending order.

        INPUT			: Type			: Node
                        : Description	: The current node in the traversal.

        OUTPUT			: Type 			: void
                        : Description	: N/A
        ***********************************************************************/
        private void InOrderTraversal(Node n)
        {
            if (n == null) return;
            InOrderTraversal(n.Left);
            Console.Write(n.Key + " ");
            InOrderTraversal(n.Right);
        }

        

        

        public class Node
        {
            private int  key;
            private int  size;
            private Node left;
            private Node right;            

            public int  Key   { get => key;   set => key   = value; }
            public int  Size  { get => size;  set => size  = value; }
            public Node Left  { get => left;  set => left  = value; }
            public Node Right { get => right; set => right = value; }            
           
            public Node(int k, int s)
            {
                Key  = k;
                Size = s;
            }           
        }
    }
}
