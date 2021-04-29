#include <iostream>
#include <list>

#include "s.hh"

using namespace std;

int main()
{
    list<int> elements = {1, 2, -2, 5, -3, 20, 50, -30, 30, 21, -4};

    list<int>::iterator it = elements.begin();
    list<int>::iterator it_end = elements.end();

    S s;

    for (; it != it_end; it++)
    {
        s.insert(*it);
    }


    cout << "tree: " << s << "\n";

    cout << "min: " << s.minimum() << '\n';
    cout << "max: " << s.maximum() << '\n';

    for (it = elements.begin(); it != it_end; it++)
    {
        try
        {
            cout << "predecessor of " << *it << " is: " << s.predecessor(*it) << "\n";
            cout << "successor of " << *it << " is: " << s.successor(*it) << "\n";
        }
        catch (const char *err)
        {
            cout << err << "\n";
        }

        cout << "\n";
    }

    return 0;
}
