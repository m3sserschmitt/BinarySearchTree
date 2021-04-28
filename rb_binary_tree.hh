#ifndef RB_BINARY_TREE_HH
#define RB_BINARY_TREE_HH

#include "binary_tree.hh"
#include "rb_node.hh"

class RBBinarySearchTree: public BinarySearchTree
{
    // rotatie spre stanga in jurul nodului x;
    void left_rotate(Node *x);

    // rotatie la dreapta in jurul nodului x;
    void right_rotate(Node *x);

    // restabileste culorile in arbore dupa inserarea unui nou nod;
    void insert_fixup(RedBlackNode *z);
public:

    RBBinarySearchTree();
    ~RBBinarySearchTree();

    void insert(Node z);
};

#endif
