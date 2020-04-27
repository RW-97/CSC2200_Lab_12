//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 2                 heapsort.cpp
//
//  ** SOLUTION: heapSort() function **
//
//--------------------------------------------------------------------

template < typename DataType >
void moveDown ( DataType dataItems [], int root, int size )

// Restores the binary tree that is rooted at root to a heap by moving
// dataItems[root] downward until the tree satisfies the heap property.
// Parameter size is the number of data items in the array.

{
    int temp = root;
    int leftNode = 2 * root + 1;
    int rightNode = 2 * root + 2;

    if (leftNode < size && dataItems[leftNode] > dataItems[temp])
    {
        temp = leftNode;
    }
    if (rightNode < size && dataItems[rightNode] > dataItems[temp])
    {
        temp = rightNode;
    }
    
    if (temp != root)
    {
        DataType tempobj = dataItems[root];
        dataItems[root] = dataItems[temp];
        dataItems[temp] = tempobj;
        moveDown(dataItems, temp, size);
    } 
   
}

//--------------------------------------------------------------------

template < typename DataType >
void heapSort ( DataType dataItems [], int size )

// Heap sort routine. Sorts the data items in the array in ascending
// order based on priority.

{
    DataType temp;   // Temporary storage
    int j;     // Loop counter

    // Build successively larger heaps within the array until the
    // entire array is a heap.

    for ( j = (size-1)/2 ; j >= 0 ; j-- )
        moveDown(dataItems,j,size);

    // Swap the root data item from each successively smaller heap with
    // the last unsorted data item in the array. Restore the heap after
    // each exchange.

    for ( j = size-1 ; j > 0 ; j-- )
    {
        temp = dataItems[j];
        dataItems[j] = dataItems[0];
        dataItems[0] = temp;
        moveDown(dataItems,0,j);
    }
}

