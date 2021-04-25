#include "node.hh"

#include <iostream>
#include "binary_tree.hh"
#include "rb_binary_tree.hh"
#include "rb_node.hh"
#include <stack>

using namespace std;

// void print_tree(stack<RedBlackNode *> &s)
// {
//     // static stack<RedBlackNode *> s;
//     // s.push(n);

//     while(not s.empty())
//     {
//         RedBlackNode *n = s.top();

//         RedBlackNode *left = dynamic_cast<RedBlackNode *>((Node *)n->get_left());
//         RedBlackNode *right = dynamic_cast<RedBlackNode *>((Node *)n->get_right());

//         if(left)
//         {
//             s.push(left);
//         }

//         if(right)
//         {
//             s.push(right);
//         }

//         cout << left << "(" << left->get_color()
//     }

// }

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
    tree.insert(200);
    tree.insert(-200);
    tree.insert(30);

    cout << tree << "\n";

    // RedBlackNode *y = new RedBlackNode(12, BLACK);
    // Node *x = y;

    // cout << *x << "\n";
    // cout << reinterpret_cast<RedBlackNode *>(x)->get_color() << "\n";


    return 0;
}

