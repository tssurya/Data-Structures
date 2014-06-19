 #ifndef __Min_Heap_H__
 #define __Min_Heap_H__

 #include <bits/stdc++.h>
 using namespace std;
 
 
//creating a template class for heap.
 template<class type>
 class Min_Heap
 {
    private:
        vector<type> heap; //the underlying container used to store the min-heap.
        size_t heap_size; //contains the size of the heap.

   	public:
        // to maintain the min-heap property by propagating the node at the 'position' upwards.
        void up_heapify(int position);

        // to maintain the min-heap property by prapagating the node at the 'position' downwards.
        void down_heapify(int position);

        // used to create the heap using the Floyd Warshall Algorithm with complexity O(n).
        void make_heap();

        // constructor to create a heap if the begining and end range of vector is given to us.
        Min_Heap(typename vector<type>::iterator heap_begin, typename vector<type>::iterator heap_end);

        // constructor to create a heap for the whole vector.
        Min_Heap(vector<type> heap);

        // to insert a new element into the heap and to re-heapify the heap to maintain the heap property.
        void push_into_heap(type value);

        // to delete the least element from the heap and restore the heap property.
        void pop_from_heap();

        //to sort the element using heap when the range of elements is given.
        void heap_sort(typename vector<type>:: iterator start,typename vector<type>:: iterator finish);

        // to return the size of the heap.
        size_t size_of_heap()
        {
            return heap_size;
        }

        // to check if the heap is empty or not.
        bool empty()
        {
            return (heap_size==0);
        }

        // to return the minimum element of the heap i.e the topmost element.
        type top()
        {
            return heap[1];
        }
 };

 #include "Min_Heap.cpp"

 #endif // __Min_Heap_H__
