#include<bits/stdc++.h>

using namespace std;

class Node
{
private:
	int data;
	Node* ptr;
public:
	Node():data(0), ptr(NULL){};
	//~Node();
	Node(int d): data(d), ptr(NULL) {};

	int get_data()
	{
		return data;
	}
	
	Node* get_ptr()
	{
		return ptr;
	}

	void set_data(int d)
	{
		data = d;
		return;
	}

	void set_ptr(Node* pointer)
	{
		ptr = pointer;
		return;
	}
};

class linked_list
{
private:
	Node* head;// actually it should be a pointer only for easier access.
	Node* tail;
	int list_size;
public:
	linked_list(): head(NULL), tail(NULL), list_size(0) {};
	//~linked_list();

	Node* get_head()
	{
		return head;
	}

	Node* get_tail()
	{
		return tail;
	}

	void push_back(int d)
	{
		Node* temp = new Node(d);
		list_size++;

		if(head == NULL and tail == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->set_ptr(temp);
			tail = temp;
		}
		return;
	}

	void push_front(int d)
	{
		Node* temp = new Node(d);
		list_size++;

		if(head == NULL and tail == NULL)
		{
			head = tail = temp;
		}
		else
		{
			temp->set_ptr(head);
			head = temp;
		}
		return;
	}

	void pop_back()
	{
		if(head == NULL and tail == NULL)
		{
			//do nothing
		}
		else if(head == tail)
		{
			Node* temp = tail;
			head = tail = NULL;
			delete temp;
			list_size--;
		}
		else
		{
			Node* prev = NULL;
			Node* cur = head;

			while(cur!=tail)
			{
				prev = cur;
				cur = cur->get_ptr();
			}

			prev->set_ptr(NULL);
			tail = prev;
			delete cur;
			list_size--;
		}

		return;

	}

	void pop_front()
	{
		if(head == NULL and tail == NULL)
		{
			//do nothing;
		}
		else if(head == tail)
		{
			Node* temp = head;
			head = tail = NULL;
			delete temp;
			list_size--;
		}
		else
		{
			Node* temp = head;
			head = head->get_ptr();
			delete temp;
			list_size--;
		}
		return;
	}

	linked_list add_list(linked_list l1, linked_list l2)
	{
		int carry = 0, sum = 0;
		Node* head1 = l1.head;
		Node* head2 = l2.head;

		linked_list ans;

		while(head1 != NULL and head2 != NULL)
		{
			sum = head1->get_data() + head2->get_data() + carry;
			carry = sum/10;
			sum = sum%10;
			ans.push_back(sum);

			head1 = head1->get_ptr();
			head2 = head2->get_ptr();
		}

		while(head1!= NULL)
		{
			sum = head1->get_data() + carry;
			carry = sum/10;
			sum = sum%10;
			ans.push_back(sum);

			head1 = head1->get_ptr();
		}

		while(head2!= NULL)
		{
			sum = head2->get_data() + carry;
			carry = sum/10;
			sum = sum%10;
			ans.push_back(sum);

			head2 = head2->get_ptr();
		}

		if(carry != 0)
		{
			ans.push_back(carry);
		}

		return ans;

	}

	void add_list_recursion(Node* head1, Node* head2, int carry)
	{
		if(head1 == NULL  and head2 == NULL) //base condition
		{
			if(carry != 0)
			{
				push_back(carry);
				return;
			}
			else
			{
				return;
			}
		}

		int value1 = head1 ? head1->get_data() : 0;
		int value2 = head2 ? head2->get_data() : 0;

		int sum = value1 + value2 + carry;
		carry = sum/10;
		sum%=10;

		push_back(sum);

		add_list_recursion(head1->get_ptr(), head2->get_ptr(), carry);

	}

	void reverse()
	{
		Node* prev = NULL;
		Node* cur = NULL;
		Node* next = head;
		while(next!=NULL)
		{
			cur = next;
			next = next->get_ptr();
			cur->set_ptr(prev);
			prev = cur;
		}
		head = cur;
		return ;
	}

	void reverse_recursion(Node* cur)
	{
		if(cur == NULL)
		{
			return;
		}
		if(cur->get_ptr() == NULL)
		{
			head = cur;
			return;
		}

		reverse_recursion(cur->get_ptr());
		cur->get_ptr()->set_ptr(cur);
		cur->set_ptr(NULL);
	}

	void print()
	{
		Node* temp = head;
		while(temp!=NULL)
		{
			cout<<temp->get_data()<<"->";
			temp = temp->get_ptr();
		}

		cout<<"\n";
		return;
	}

	void merge (Node* head1, Node* head2)
	{
		while(head1!=NULL and head2!=NULL)
		{
			if(head1->get_data() <= head2->get_data())
			{
				push_back(head1->get_data());
				head1 = head1->get_ptr();
			}
			else
			{
				push_back(head2->get_data());
				head2=head2->get_ptr();
			}
		}

		if(head1 == NULL)
			this->tail->set_ptr(head2);
		if(head2 == NULL)
			this->tail->set_ptr(head1);

		return;

	}

	int midpoint()
	{
		Node* slow = head;
		Node* fast = head;

		while(fast!= NULL and fast->get_ptr()!=NULL)
		{
			slow = slow->get_ptr();
			fast = fast->get_ptr()->get_ptr();
		}

		return slow->get_data();
	}
	
};

int main()
{
	linked_list l1;
	l1.push_back(1);
	l1.push_back(4);
	l1.push_back(7);
	l1.push_back(9);
	l1.print();
	linked_list l2;
	l2.push_back(9);
	l2.push_back(15);
	l2.push_back(20);
	l2.print();

	linked_list ans;
	//ans.add_list_recursion(l1.get_head(), l2.get_head(), 0);
	//ans.print()
	//cout<<"\n";
	//ans = ans.add_list(l1, l2);
	//ans.print();
	//l1.reverse();
	//l1.print();
	//ans.reverse_recursion(l1.get_head());
	//ans.print();
	//ans.merge(l1.get_head(), l2.get_head());
	//ans.print();

	int res = l1.midpoint();
	printf("%d\n", res );
	return 0;
}