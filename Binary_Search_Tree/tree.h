#include "Node.h"
#include <iostream>
using namespace std;
class tree
{
    private:

        Node *root;
        size_t tree_size;
        static int deletion_flag;

    public:

        tree():root(NULL), tree_size(0)
        {}

        //insert a ndoe into the tree.
        void insert (int x);

        Node* get_root()
        {
            return root;
        }

        size_t size()
        {
            return tree_size;
        }

        bool empty()
        {
            return (tree_size == 0);
        }

        //traverse the tree from the given node.
        void inorder (Node *node_ptr, ostream& out = cout);
        void preorder (Node *node_ptr, ostream& out = cout);
        void postorder (Node *node_ptr, ostream& out = cout);
        void level_order (Node *node_ptr, ostream& out = cout);

        //traverse the tree from the root always.
        void inorder(ostream& out = cout);
        void preorder (ostream& out = cout);
        void postorder (ostream& out = cout);
        void level_order (ostream& out = cout);

        //search for a key
        Node* search(int key);

        bool delete_node (int value);
        bool delete_node (Node* node);

        Node* get_parent(Node* node);
        Node* get_parent(int value);

        Node* get_inorder_successor(Node* node);
        Node* get_inorder_successor(int value);

        Node* get_inorder_predecessor(Node* node);
        Node* get_inorder_predecessor(int value);

        bool is_root(Node* node);
        bool is_root(int value);

        bool is_leaf(Node* node);
        bool is_leaf(int value);

        bool has_only_one_sibling(Node* node);
        bool has_only_one_sibling(int value);

        bool has_two_siblings(Node* node);
        bool has_two_siblings(int value);

        bool is_left_child(Node* node);
        bool is_left_child(int value);
        bool is_right_child(Node* node);
        bool is_right_child(int value);

        void clear();
        void clear(Node* node);

};
