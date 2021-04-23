#include "node.hh"

#include <iostream>

using namespace std;

int main()
{
    Node n = 5;

    Node m = n;

    cout << n << "\n";
    cout << m << "\n";

    n = 6;

    cout << n << "\n";

    cin >> m;

    cout << m << "\n";

    return 0;
}