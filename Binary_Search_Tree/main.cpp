#include "tree.h"
#include <iostream>
#include <array>
using namespace std;

int main()
{
    tree t;
    array<int,8> data = {4, 2, 1, 3, 6, 5, 7, 8};
    array<int,8> ::iterator itr;
    Node* node_ptr=NULL;
    for(itr=data.begin();itr!=data.end();itr++)
    {
        t.insert(*itr);
    }
    cout<<"Inorder:", t.inorder(),cout<<endl;
    //accordingly we can test other functions of the tree as well.
    return 0;
}
