#include<bits/stdc++.h>

using namespace std;

class Node
{
private:
    int data;
    Node* prev_ptr;
    Node* next_ptr;
public:
    Node():data(0), prev_ptr(NULL), next_ptr(NULL) {};
    Node(int d): data(d), prev_ptr(NULL), next_ptr(NULL) {};
    ~Node(){};
    

    int get_data()
    {
        return data;
    }
    
    Node* get_prev_ptr()
    {
        return prev_ptr;
    }

    Node* get_next_ptr()
    {
        return next_ptr;
    }

    void set_data(int d)
    {
        data = d;
        return;
    }

    void set_prev_ptr(Node* pointer)
    {
        prev_ptr = pointer;
        return;
    }

    void set_next_ptr(Node* pointer)
    {
        next_ptr = pointer;
        return;
    }
};

class linked_list
{
private:
    Node sentinal_head;
    Node sentinal_tail;
    int list_size;
public:
    linked_list(): sentinal_head(), sentinal_tail(), list_size(0) {};
    ~linked_list(){};

    void push_back(int d)
    {
        Node* temp = new Node(d);
        list_size++;

        if(sentinal_head.get_next_ptr() == NULL and sentinal_tail.get_prev_ptr() == NULL)
        {
            sentinal_head.set_next_ptr(temp);
            sentinal_tail.set_prev_ptr(temp);
            temp->set_prev_ptr(&sentinal_head);
            temp->set_next_ptr(&sentinal_tail);
        }
        else
        {
            Node* second_last = sentinal_tail.get_prev_ptr();
            second_last->set_next_ptr(temp);
            temp->set_next_ptr(&sentinal_tail);
            temp->set_prev_ptr(second_last);
            sentinal_tail.set_prev_ptr(temp);
        }
        
        return;
    }

    void push_front(int d)
    {
        Node* temp = new Node(d);
        list_size++;

        if(sentinal_head.get_next_ptr() == NULL and sentinal_tail.get_prev_ptr() == NULL)
        {
            sentinal_head.set_next_ptr(temp);
            sentinal_tail.set_prev_ptr(temp);
            temp->set_prev_ptr(&sentinal_head);
            temp->set_next_ptr(&sentinal_tail);
        }
        else
        {
            Node* second = sentinal_head.get_next_ptr();
            second->set_prev_ptr(temp);
            temp->set_next_ptr(second);
            temp->set_prev_ptr(&sentinal_head);
            sentinal_head.set_next_ptr(temp);
        }
        return;
    }

    void pop_back()
    {
        if(sentinal_head.get_next_ptr() == NULL and sentinal_tail.get_prev_ptr() == NULL)
        {
            //do nothing
        }
        else if(sentinal_head.get_next_ptr() == sentinal_tail.get_prev_ptr())
        {
            Node* temp = sentinal_tail.get_prev_ptr();
            sentinal_head.set_next_ptr(NULL);
            sentinal_tail.set_prev_ptr(NULL);
            delete temp;
            list_size--;
        }
        else
        {
            Node* temp = sentinal_tail.get_prev_ptr();
            Node* second_last = temp->get_prev_ptr();
            second_last->set_next_ptr(&sentinal_tail);
            sentinal_tail.set_prev_ptr(second_last);
            delete temp;
            list_size--;
        }

        return;

    }

    void pop_front()
    {
        if(sentinal_head.get_next_ptr() == NULL and sentinal_tail.get_prev_ptr() == NULL)
        {
            //do nothing;
        }
        else if(sentinal_head.get_next_ptr() == sentinal_tail.get_prev_ptr())
        {
            Node* temp = sentinal_head.get_next_ptr();
            sentinal_head.set_next_ptr(NULL);
            sentinal_tail.set_prev_ptr(NULL);
            delete temp;
            list_size--;
        }
        else
        {
            Node* temp = sentinal_head.get_next_ptr();
            Node* second = temp->get_next_ptr();
            second->set_prev_ptr(&sentinal_head);
            sentinal_head.set_next_ptr(second);
            delete temp;
            list_size--;
        }
        return;
    }

    void print()
    {
        Node* temp = sentinal_head.get_next_ptr();

        if(temp == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            while(temp!=&sentinal_tail)
            {
                cout<<temp->get_data();
                temp = temp->get_next_ptr();
            }
        
        }
        return;
    }
    
};

int main()
{
    linked_list l ;
    
    l.push_back(10);
    l.push_back(20);
    l.push_front(30);
    l.print();
    l.pop_back();
    l.pop_front();
    cout<<"\n";
    l.print();
    //cout << l->list_size;
    cout<<"\n";
    l.pop_back();
    l.print();
    
    return 0;
}