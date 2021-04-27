#ifndef RB_BINARY_TREE_HH
#define RB_BINARY_TREE_HH

#include "binary_tree.hh"
#include "rb_node.hh"

class RBBinarySearchTree: public BinarySearchTree
{
    void left_rotate(Node *x);
    void right_rotate(Node *x);

    void insert_fixup(RedBlackNode *z);
public:

    RBBinarySearchTree();
    ~RBBinarySearchTree();

    void insert(Node z);

};

#endif
