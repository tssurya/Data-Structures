#include "stack.h"
#include <cstring>
#include <iostream>
using namespace std;

int main()
{

    Stack<string> stk;
    string cmd;
    string data;
    while(1)
    {
        try
        {
            cin>>cmd;
            if(cmd=="push") cin>>data;
            if(cmd=="push") stk.push(data);
            else if(cmd=="pop") stk.pop();
            else if(cmd=="print") cout<<stk<<endl;
            else if(cmd=="exit") break;
            else    cout<<"Wrong command"<<endl;
        }
        catch(const overflow_error& e)
        {
            cerr<<e.what()<<endl;
        }
        catch(const underflow_error& e)
        {
            cerr<<e.what()<<endl;
        }
    }
    return 0;
}

