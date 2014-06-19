#include "Min_Heap.h"

//constuctor to construct the heap when a range of the vector is given.
template<class type>
Min_Heap<type>:: Min_Heap(typename vector<type>:: iterator data_begin,typename vector<type>:: iterator data_end)
{
    assert(data_end-data_begin > 0); //ensure that there is at least one element in the range.
    heap_size=data_end-data_begin;// assigning the size of the range to the heap.
    heap.push_back(0);//to make the heap 1-based index

    //loop to insert the elements within the range into the heap.
    for(typename vector<type>:: iterator it=data_begin; it!= data_end; it++)
    {
        heap.push_back(*it);
    }

    //function to create the heap using the Flyod's heap creation algorithm.
    make_heap();
}
// constructor to construct the heap when a whole vector is given.
template<class type>
Min_Heap<type>:: Min_Heap(vector<type> data)
{
    assert(data.end()-data.begin() > 0);// ensure that vector contains at least one element, else exit.
    heap_size=data.end()-data.begin();// assigning the size of the vector to the size of heap.
    heap.push_back(0);// to make the heap 1-based index.

    //loop to push the elements into the heap.
    for(typename vector<type>:: iterator it=data.begin();it!=data.end();it++)
    {
        heap.push_back(*it);
    }

    //function to create the heap using the Floyd's heap creation algorithm.
    make_heap();
}

// Floyd's heap creation algorithm with Complexity O(n).
template<class type>
void Min_Heap<type> :: make_heap()
{
    if(heap.size() <= 1)
        return;

    //loop starting from the last non-leaf node to perform the down-heapification process.
    for(int index=heap.size()/2; index>=1 ;index-- )
    {
        down_heapify(index);
    }
}

/*function to move the node down such that the heap property is maintained.
this function is used during the creation of heap and deletion of the root element.
The steps are:-

1 Compare the parent with its children.
2 if they are in correct order then stop.
3 else swap the parent with the smallest of its children.
4 return to step 1. */

template<class type>
void Min_Heap<type> :: down_heapify(int index)
{
    int left_child = index << 1;
    int right_child = left_child | 1;
    int smallest=index;

    if(left_child < heap.size() and heap[left_child]<heap[smallest])
    {
        smallest=left_child;
    }

    if(right_child < heap.size() and heap[right_child]<heap[smallest])
    {
        smallest=right_child;
    }

    if(smallest!=index)
    {
        swap(heap[index],heap[smallest]);
        down_heapify(smallest);
    }
}

/* function to move the node up such that the heap property is maintained.
this is done when a new node is inserted into the heap.
The steps are:-

1 Get the parent of the node.
2 Compare the value of the node with its parent.
3 If it is against the heap property then swap.
4 Goto step 1 from the parent. */

template<class type>
void Min_Heap<type>::up_heapify(int index)
{
    assert(index<=heap.size());
    int parent=index/2;

    if(heap[parent]>heap[index])
    {
        swap(heap[parent],heap[index]);
        up_heapify(parent);
    }
    return;
}

/*function to push a new element-value into the heap.
the element is inserted into the end of the heap.
from there the up_heapify is done to restore the heap property. */

template<class type>
void Min_Heap<type>:: push_into_heap(type value)
{
    heap.push_back(value);
    heap_size++;
    up_heapify(heap.size());
    return;
}

/*function to pop an element from the heap.
that is to delete the topmost element from the heap.
swap the element at the top of the heap with the last element of the heap and do down_heapify to restore the heap property. */

template<class type>
void Min_Heap<type>::pop_from_heap()
{
    if(heap.size()==1)
    {
        heap.clear();
        heap_size=0;
    }
    else
    {
        heap[1]=heap[heap.size()];
        --heap_size;
        heap.pop_back();
        down_heapify(1);
    }
}

/* function to sort the elements in the given range.
Since the min-heap contains the smallest element at the top always ,
we keep deleting the top most element from the heap and then restoring heap property.
this is done till there are no more elements in the heap.
The deleted elements in their order gives the sorted elements. */

template<class type>
void Min_Heap<type>::heap_sort(typename vector<type>:: iterator start,typename vector<type>:: iterator finish)
{
    typename vector<type>:: iterator it=start;
    Min_Heap<type>  temp_heap(start,finish);//creating a heap using the constructor.

    while(!temp_heap.empty())
    {
        *it=temp_heap.top();
        it++;
        temp_heap.pop_from_heap();
    }
    return;
}

