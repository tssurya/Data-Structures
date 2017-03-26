#include <bits/stdc++.h>

using namespace std;

class Max_Heap
{
	private:
		int heap_size;
		vector<int> v;
		void down_heapify(int index);
		void up_heapify(int index);
		void make_heap();
	public:
		int get_size()
		{
			return heap_size;
		}

		int peek()
		{
			return v[1];
		}

		Max_Heap(vector<int> heap)
		{
			heap_size = heap.size();
			v.push_back(0);
			for(vector<int>::iterator i = heap.begin(); i!= heap.end(); i++)
			{
				v.push_back(*i);
			}
			make_heap();
		}
		//O(log n)
		void push_back(int d)
		{
			v.push_back(d);
			heap_size++;
			up_heapify(heap_size);
			return;
		}
		//O(log n)
		void pop()// without any actual deletion.
		{
			if(heap_size == 0)
				return;
			
			int temp = v[1];
			v[1] = v[heap_size];
			v[heap_size] = temp;
			heap_size--;
			down_heapify(1);			
			return;
		}

		vector<int> sort(vector<int>::iterator begin, vector<int>:: iterator end)
		{
			//v.clear();
			//heap_size = end - begin;
			//v.push_back(0);
			//for(vector<int>::iterator i = begin; i!= end; i++)
			//{
			//	v.push_back(*i);
			//}
			//make_heap();
			
			while(heap_size > 0)
			{
				pop();
			}
			
			return v;
		}

		void print()
		{
			for(int i = 1; i <= heap_size; i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<"\n";
		}
};

//O(log n)
void Max_Heap::down_heapify(int index)
{
	if(index > heap_size)
		return;
	int left_child = (index << 1);
	int right_child = (left_child) | 1;
	int largest = index;
	if(left_child <= heap_size and v[left_child] > v[largest])
	{
		largest = left_child;
	}
	if(right_child <= heap_size and v[right_child] > v[largest])
	{
		largest = right_child;
	}
	if(largest != index)
	{
		int temp = v[index];
		v[index] = v[largest];
		v[largest] = temp;
		down_heapify(largest);
	}
	return;
}
//O(log n)
void Max_Heap::up_heapify(int index)
{
	if(index > heap_size)
		return;
	int parent = floor(index/2);
	if(v[index] > v[parent])
	{
		int temp = v[parent];
		v[parent] = v[index];
		v[index] = temp;
		up_heapify(parent);
	}
	return;
}
//O(n) - using Floyd's Method
void Max_Heap::make_heap()
{
	if(heap_size <= 1)
		return;
	int last_non_leaf_node = heap_size/2;
	for(int i = last_non_leaf_node; i >=1; i--)
	{
		down_heapify(i);
	}
	return;
}


int main()
{
	int arr[] = {1, 5, 9, 3, 10, 20, 12, 50, 6, 25};
	vector<int> h1 (arr, arr + ( sizeof(arr)/sizeof(arr[0]) ) );
	Max_Heap H1(h1);
	H1.print();
	//cout<<"hello";
	vector<int> ans = H1.sort(h1.begin(), h1.end());
	//vector<int> ans = sort(H1.v.begin(), H1.v.end());
	for(int i =1; i < ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}