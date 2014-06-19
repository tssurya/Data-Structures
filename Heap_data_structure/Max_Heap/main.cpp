#include "Max_Heap.h"

int main()
{
    vector<int> v;
    for(int index=5;index<=15;index++)
    {
        v.push_back(index);
    }
    Max_Heap<int> heap(v);
    heap.pop_from_heap();
    heap.push_into_heap(1);
    heap.heap_sort(v.begin(),v.end());

    return 0;
}

