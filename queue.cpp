#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
	static const int size = 5;
	int data[size];
	int front;
	int rear;
	int queue_size;
public:
	Queue(): front(-1), rear(-1), queue_size(0) 
	{
		for (int i = 0; i < size; ++i)
		{
			data[i] = 0;
		}
	};
	~Queue(){};

	int& get_front()
	{
		return data[front];
	}

	int& get_rear()
	{
		return data[rear];
	}

	int get_queue_size()
	{
		return queue_size;
	}

	void push(int d)
	{
		if(front == rear+1 or (front == 0 and rear == size-1))
		{
			cout<<"queue is full\n";
		}
		else
		{
			if(queue_size == 0)
			{
				front = rear = 0;
				data[rear] = d;
			}
			else
			{
				rear = (rear == size-1) ? 0 : rear+1;
				data[rear] = d;
			}
			queue_size++;
		}
		return;
	}

	void pop()
	{
		if(queue_size == 0)
		{
			cout<<"queue is empty\n";
		}
		else
		{
			if(queue_size == 1)
			{
				data[front] = 0;
				front = rear = -1;
			}
			else
			{
				data[front] = 0;
				front = (front == size-1) ? 0 : front+1;
			}
			queue_size--;
		}
		return;
	}

	void print()
	{
		
		cout<<"-------------------\n";
		for (int i = 0; i<size; i++)
		{
			//cout<<i;
			cout<<"|"<<data[i];
			//cout<<"------\n";
		}
		//cout<<"|"<<data[rear]<<"|\n";
		cout<<"\n--------------------\n";
		return;
	}
};

int main()
{
	Queue q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.print();
	q.push(60);
	q. pop();
	q.pop();
	q.print();
	q.push(60);
	q.print();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.print();
	return 0;
}