#include <iostream>
#include <list>
#include <set>

#include "s.hh"

using namespace std;

int main()
{
    list<int> elements = {1, 2, 3, 4, 5, 3, 10, -2, -4, 2, 1, 4, 3};
    set<int> dist_elements;

    list<int>::iterator it = elements.begin();
    list<int>::iterator it_end = elements.end();

    S s;

    for (; it != it_end; it++)
    {
        s.insert(*it);
        dist_elements.insert(*it);
    }

    //cout << s.kth_element(7) << "\n";

    // cout << s.exists(200) << "\n";

    s.delete_node(10);

    cout << "tree: " << s << "\n";

    /* cout << "min: " << s.minimum() << '\n';
    cout << "max: " << s.maximum() << '\n';

    set<int>::iterator dist_it = dist_elements.begin();
    set<int>::iterator dist_it_end = dist_elements.end();

    for (; dist_it != dist_it_end; dist_it++)
    {
        try
        {
            cout << "predecessor of " << *dist_it << " is: " << s.predecessor(*dist_it) << "\n";
        }
        catch (const char *err)
        {
            cout << err << "\n";
        }

        try
        {
            cout << "successor of " << *dist_it << " is: " << s.successor(*dist_it) << "\n";
        }
        catch (const char *err)
        {
            cout << err << "\n";
        }

        cout << "\n";
    }
*/
    return 0;
}
