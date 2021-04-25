#ifndef RB_BINARY_TREE_HH
#define RB_BINARY_TREE_HH

#include "binary_tree.hh"
#include "rb_node.hh"

class RBBinarySearchTree: public BinarySearchTree
{
    RedBlackNode *nil;

    void left_rotate(Node *x);
    void right_rotate(Node *x);

    void insert_fixup(RedBlackNode *z);

    std::ostream &in_order_tree_print(std::ostream &out, const Node *x) const;
public:
    RBBinarySearchTree();
    ~RBBinarySearchTree();

    void insert(Node z);

    // void print_tree();
};

#endif
