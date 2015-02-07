#include<iostream>

using namespace std;

class Node
{
    private:

        int data;
        Node* left_ptr;
        Node* right_ptr;

    public:

        Node():data(0),left_ptr(NULL),right_ptr(NULL)
        {}

        Node(int d):data(d),left_ptr(NULL),right_ptr(NULL)
        {}

        void set_data(int d)
        {
            data=d;
            return;
        }

        int get_data()
        {
            return data;
        }

        void set_left_ptr(Node* temp_ptr)
        {
            left_ptr=temp_ptr;
            return;
        }

        Node* get_left_ptr()
        {
            return left_ptr;
        }

        void set_right_ptr(Node* temp_ptr)
        {
            right_ptr=temp_ptr;
            return;
        }

        Node* get_right_ptr()
        {
            return right_ptr;
        }
};
