#include "node.hh"

#include <iostream>
#include "binary_tree.hh"
#include "rb_binary_tree.hh"
#include "rb_node.hh"
#include <stack>

using namespace std;

int main()
{
    RBBinarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(-10);
    tree.insert(12);
    tree.insert(22);
    tree.insert(-12);
    tree.insert(100);
    tree.insert(201);
    tree.insert(-200);
    tree.insert(30);

    cout << tree << "\n";

    // cout << tree.minimum() << '\n';
    // cout << tree.maximum() << '\n';

    int m = tree.minimum();
    cout << "min: " << m << "\n";

    cout << tree.successor(30) << '\n';
    cout << tree.predecessor(12) << '\n';

    // RedBlackNode *y = new RedBlackNode(12, BLACK);
    // Node *x = y;

    // cout << *x << "\n";
    // cout << reinterpret_cast<RedBlackNode *>(x)->get_color() << "\n";


    return 0;
}

