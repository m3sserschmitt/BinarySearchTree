#include "node.hh"

#include <iostream>
#include "binary_tree.hh"
#include "rb_binary_tree.hh"
#include "rb_node.hh"
#include <list>

using namespace std;

int main()
{
    list<int> elements = {1, 2, 54, -2, -4, 10, -10, 20, 45, 12, 45, 100, 300, 500, -201};

    list<int>::iterator it = elements.begin();
    list<int>::iterator it_end = elements.end();

    RBBinarySearchTree tree;

    for (; it != it_end; it++)
    {
        tree.insert(*it);
    }

    cout << "tree: " << tree << "\n";

    cout << "min: " << tree.minimum() << '\n';
    cout << "max: " << tree.maximum() << '\n';

    // for (it = elements.begin(); it != it_end; it++)
    // {
    //     try
    //     {
    //         cout << "predecessor of " << *it << " is: " << tree.predecessor(*it) << "\n";
    //         cout << "successor of " << *it << " is: " << tree.successor(*it) << "\n";
    //     }
    //     catch (const char *err)
    //     {
    //         cout << err << "\n";
    //     }

    //     cout << "\n";
    // }

    return 0;
}
