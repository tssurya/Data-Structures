#include <bits/stdc++.h>
using namespace std;

class int_stack
{
private:
	static const int size = 5; // this is the limit of the stack.
	int data[size];
	int stack_pointer;
public:
	int_stack() : stack_pointer(-1) {};
	~int_stack(){};

	bool is_empty()
	{
		return (stack_pointer == -1);
	}

	bool is_full()
	{
		return (stack_pointer+1 == size);
	}

	int get_stack_size()
	{
		return stack_pointer+1;
	}
	// reference is not a pointer actually and neither does it contain the address of the variable it is pointing to 
	// reference is just used to implement a new name for an existing object. ->basically the call by reference concept.
	int& top() //it should return a 'reference' to the top of the stack
	{
		return data[stack_pointer];
	}

	void push(int d)
	{
		if(is_full())
		{
			cout<<"stack overflow\n";
		}
		else
		{
			data[++stack_pointer] = d;
		}
		return;
	}

	void pop()
	{
		if(is_empty())
		{
			cout<<"stack underflow\n";
		}
		else
		{
			stack_pointer--;
		}
		return;
	}

	void print()
	{
		cout<<"------\n";
		for (int i = stack_pointer; i >= 0; --i)
		{
			cout<<"| "<<data[i]<<" |\n";
			cout<<"------\n";
		}
		return;
	}
};

int main()
{
	int_stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.print();
	s.push(60);
	s.pop();
	s.print();
	s.pop();
	s.pop();
	s.print();
	s.pop();
	return 0;
}