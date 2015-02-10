#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <fstream>
#include <climits>
#include <stdexcept>
#include <cstdlib>

using namespace std;
template<class type>class Stack;
template <class type>
class Stack
{
    public:

        typedef size_t size_type;
        typedef type value_type;

    private:

        static const size_t stack_size = 10;
        value_type data[stack_size];
        signed int top_of_stack;

    public:

        Stack():top_of_stack(-1)
        {}

        bool empty() const
        {
            return (top_of_stack==-1);
        }

        size_type size() const
        {
            return size_type(top_of_stack+1);
        }

        value_type& top()
        {
            return data[top_of_stack];
        }

        const value_type& top() const
        {
            return data[top_of_stack];
        }

        void push(const value_type& x);
        void pop();

        friend ostream& operator<< <type> (ostream& out, const Stack<type>& s);
};
#include "stack.cpp"

#endif
