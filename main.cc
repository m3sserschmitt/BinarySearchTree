#include "node.hh"

#include <iostream>
#include "binary_tree.hh"
#include "rb_node.hh"

using namespace std;

int main()
{
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(-10);
    tree.insert(12);
    tree.insert(22);
    tree.insert(-12);
    tree.insert(100);
    tree.insert(200);
    tree.insert(-200);
    tree.insert(30);

    cout << tree << "\n";

    return 0;
}

