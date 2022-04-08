/*
    Disjoint set data structure as described in Sedgewick's Algorithms
    (see p. 216 for details)
/**/

#include <iostream>
#include <utility>
#include "DisjointSet.h"

using namespace std;

int main()
{
    cout << "Enter the number of sites\n";
    size_t n = 0;
    cin >> n;
    DisjointSet set(n);

    while (cin) {
        size_t p = 0;
        size_t q = 0;
        cin >> p >> q;
        if (!cin) break;

        if (set.connected(p, q)) {
            cout << "sites " << p << " and " << q
                << " are already connected\n";
            continue;
        }
        else {
            set.unify(p, q);
            cout << "connected " << p << " and " << q << '\n';
        }
    }
    cout << "There's a total of " << set.count() << " components\n";

    return 0;
}
