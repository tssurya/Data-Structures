#include "tree.h"
#include <iostream>
#include<queue>
using namespace std;
int tree:: deletion_flag = 0;

void tree::insert(int x)
{
    if(tree_size == 0)
    {
        Node* node = new Node(x);
        tree_size ++;
        root = node;
    }
    else
    {
        Node* node = new Node(x);
        Node* temp = root;
        while(1)
        {
            if(temp->get_data() > x)
            {
                //traverse the left subtree
                if(temp->get_left_ptr()==NULL)
                {
                    temp->set_left_ptr(node);
                    break;
                }
                else
                {
                    temp=temp->get_left_ptr();
                }
            }
            else if(temp->get_data() < x)
            {
                //need to traverse the right sub tree
                if(temp->get_right_ptr()== NULL)
                {
                    temp->set_right_ptr(node);
                }
                else
                {
                    temp=temp->get_right_ptr();
                }
            }
            else
            {
                return;
            }

        }
        ++tree_size;

    }
    return;
}

void tree::inorder(Node *node_ptr, ostream& out)
{
    if(node_ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(node_ptr->get_left_ptr(), out);
        out << node_ptr->get_data()<< " ";
        inorder(node_ptr->get_right_ptr(), out);
    }

    return;
}

void tree::inorder(ostream& out)
{
    inorder(get_root(),out);
    return;
}

void tree::preorder(Node* node_ptr, ostream& out)
{
    if(node_ptr == NULL)
    {
        return;
    }
    else
    {
        out << node_ptr->get_data()<<" ";
        preorder(node_ptr->get_left_ptr(),out);
        preorder(node_ptr->get_right_ptr(), out);
    }
    return;
}

void tree:: preorder(ostream& out)
{
    preorder(get_root());
    return;
}

void tree::postorder(Node* node_ptr, ostream& out)
{
    if(node_ptr == NULL)
    {
        return;
    }
    else
    {
        postorder(node_ptr,out);
        postorder(node_ptr,out);
        out << node_ptr->get_data() << " ";
    }
    return;
}

void tree::postorder(ostream& out)
{
    postorder(get_root(), out);
    return;
}

void tree::level_order(Node* node_ptr, ostream& out)
{
    if(node_ptr == NULL)
    {
        return;
    }
    queue<Node*> q;
    Node* next_node;
    q.push(node_ptr);
    while(!q.empty())
    {
        next_node = q.front();
        q.pop();
        out << next_node->get_data() << " ";
        if(next_node->get_left_ptr()!=NULL)
        {
            q.push(next_node->get_left_ptr());
        }
        if(next_node->get_right_ptr()!=NULL)
        {
            q.push(next_node->get_right_ptr());
        }
    }
    return;
}

void tree:: level_order(ostream& out)
{
    level_order(get_root(), out);
    return;
}

Node* tree:: search(int value)
{
    Node* curr_node = get_root();
    while(curr_node!= NULL)
    {
        if(value == curr_node->get_data())
        {
            return curr_node;
        }
        else if(value < curr_node->get_data())
        {
            curr_node = curr_node->get_left_ptr();
        }
        else if(value > curr_node->get_data())
        {
            curr_node = curr_node->get_right_ptr();
        }
    }
    return NULL;
}

Node* tree::get_inorder_successor(Node* node)
{
    if(node == NULL)
    {
        return NULL;
    }
    else{
        if(node->get_right_ptr()!=NULL)
        {
            /*right sub tree is not null.
            so return the leftmost child of the right sub tree.
            complexity: O(log n).*/
            Node* curr_node = node->get_right_ptr();
            while(curr_node->get_left_ptr()!=NULL)
            {
                curr_node=curr_node->get_left_ptr();
            }
            return curr_node;
        }
        else
        {
            /* start from the root.
            keep saving the left child as you go down the left of the tree.*/
            Node* succ_node = NULL;
            Node* curr_node = get_root();
            while(curr_node!=NULL)
            {
                if(node->get_data() <curr_node->get_data())
                {
                    succ_node = curr_node;
                    curr_node=curr_node->get_left_ptr();
                }
                else if(node->get_data()>curr_node->get_data())
                {
                    curr_node=curr_node->get_right_ptr();
                }
                else
                {
                    break;
                }
            }
            return succ_node;
        }
    }
}
Node* tree::get_inorder_successor(int value)
{
    Node* node_ptr=search(value);
    return get_inorder_successor(node_ptr);
}

Node* tree::get_inorder_predecessor(Node* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else
    {
        if(node->get_left_ptr()!=NULL)
        {
            //if left sub tree is not null return the rightmost child of the left subtree.
            Node* curr_node=node->get_left_ptr();
            while(curr_node->get_right_ptr()!=NULL)
            {
                curr_node=curr_node->get_right_ptr();
            }
            return curr_node;
        }
        else

        {
            /*left sub tree is null.
            so start from the root.
            save the node when moving to the right of the tree*/
            Node *succ_node = NULL;
            Node *curr_node = get_root();
            while(curr_node!=nullptr)
            {
                if(node->get_data()<curr_node->get_data())
                {
                    curr_node=curr_node->get_left_ptr();
                }
                else if(node->get_data()>curr_node->get_data())
                {
                    succ_node=curr_node;
                    curr_node=curr_node->get_right_ptr();
                }
                else
                {
                    break;
                }
            }
            return succ_node;
        }
    }
}
Node* tree::get_parent(Node* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    Node *curr_node=get_root();
    Node *prev_node=NULL;

    while(curr_node!=NULL)
    {
        if(node->get_data()==curr_node->get_data())
        {
            return prev_node;
        }
        else
        {
            prev_node=curr_node;
            if(node->get_data()<curr_node->get_data())
            {
                curr_node=curr_node->get_left_ptr();
            }
            else if(node->get_data()>curr_node->get_data())
            {
                curr_node=curr_node->get_right_ptr();
            }
        }
    }
    return NULL;
}
Node* tree::get_parent(int value)
{
    Node* node=search(value);
    return get_parent(node);
}

bool tree::is_left_child(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    if(is_root(node))
    {
        return false;
    }
    else
    {
        return (get_parent(node)->get_left_ptr()==node);
    }
}
bool tree::is_left_child(int value)
{
    Node* node=search(value);
    return is_left_child(node);
}
bool tree::is_right_child(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    if(is_root(node))
    {
        return false;
    }
    else
    {
        return (get_parent(node)->get_right_ptr()==node);
    }
}
bool tree::is_root(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    return (get_root()==node);
}
bool tree::is_root(int value)
{
    return get_root()->get_data()==value;
}
bool tree::is_right_child(int value)
{
    Node* node=search(value);
    return is_right_child(node);
}
bool tree::is_leaf(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    return((node->get_left_ptr()==NULL) and (node->get_right_ptr()==NULL));
}
bool tree::is_leaf(int value)
{
    Node* node = search(value);
    return is_leaf(node);
}
bool tree::has_two_siblings(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    else
    {
        return ((node->get_left_ptr()!=NULL)and (node->get_right_ptr()!=NULL));
    }
}
bool tree::has_two_siblings(int value)
{
    Node* node_ptr=search(value);
    return has_two_siblings(node_ptr);
}
bool tree::has_only_one_sibling(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    return(((node->get_left_ptr()!=NULL)and (node->get_right_ptr()==NULL))or((node->get_left_ptr()==NULL)and(node->get_right_ptr()!=NULL)));
}
bool tree::has_only_one_sibling(int value)
{
    Node* node=search(value);
    return has_only_one_sibling(node);
}
bool tree::delete_node(int value)
{
    Node* node =search(value);
    return delete_node(node);
}
bool tree::delete_node(Node* node)
{
    if(node==NULL)
    {
        return false;
    }
    else
    {
        if(is_leaf(node))
        {
            /*just delete it*/
            if(is_root(node))
            {
                root=NULL;
            }
            else if(is_left_child(node))
            {
                get_parent(node)->set_left_ptr(NULL);
            }
            else
            {
                get_parent(node)->set_right_ptr(NULL);
            }
            delete node;
            --tree_size;
            return true;
        }
        else
        {
            if(has_only_one_sibling(node))
            {
                if(node->get_left_ptr()!=NULL)
                {
                    if(is_left_child(node))
                    {
                        get_parent(node)->set_left_ptr(node->get_left_ptr());
                    }
                    else if(is_right_child(node))
                    {
                        get_parent(node)->set_right_ptr(node->get_left_ptr());
                    }
                    else
                    {
                        root=node->get_left_ptr();
                    }
                    delete node;
                    --tree_size;
                    return true;
                }
                else
                {
                    if(is_left_child(node))
                    {
                        get_parent(node)->set_left_ptr(node->get_right_ptr());
                    }
                    else if(is_right_child(node))
                    {
                        get_parent(node)->set_right_ptr(node->get_right_ptr());
                    }
                    else
                    {
                        root=node->get_right_ptr();
                    }
                    delete root;
                    --tree_size;
                    return true;
                }
            }
            else
            {
                //has two siblings
                Node* inorder_successor_or_predecessor= NULL;
                if(deletion_flag==0)
                {
                    deletion_flag=1;
                    inorder_successor_or_predecessor=get_inorder_successor(node);
                }
                else
                {
                    deletion_flag=0;
                    inorder_successor_or_predecessor=get_inorder_predecessor(node);
                }

                int temp=inorder_successor_or_predecessor->get_data();
                delete_node(inorder_successor_or_predecessor);
                node->set_data(temp);
                return false;
            }
        }
    }
}
void tree::clear()
{
    clear(get_root());
    root=NULL;
    return;
}
void tree::clear(Node* node)
{
    if(node==NULL)
        return;
    else
    {
        clear(node->get_left_ptr());
        clear(node->get_right_ptr());
        if(!is_root(node))
        {
            if(is_left_child(node))
            {
                get_parent(node)->set_left_ptr(NULL);
            }
            else if(is_right_child(node))
            {
                get_parent(node)->set_right_ptr(NULL);
            }
        }
        delete node;
        --tree_size;
    }
}

