/*
    Disjoint set data structure as described in Sedgewick's Algorithms
    (see p. 216 for details)
/**/

#include <iostream>
#include <utility>
#include <cstring>
#include "DisjointSet.h"

using namespace std;

int main(int argc, char* argv[])
{
    // parse the arguments
    bool print_intermediate = true;
    if (argc > 1) {
        //cout << argv[1] << '\n';
        if (strcmp(argv[1], "no_print") == 0) print_intermediate = false;
    }

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
            if (print_intermediate) {
                cout << "sites " << p << " and " << q
                    << " are already connected\n";
            }
            continue;
        }
        else {
            set.unify(p, q);
            if (print_intermediate) {
                cout << "connected " << p << " and " << q << '\n';
            }
        }
    }
    cout << "There's a total of " << set.count() << " components\n";

    return 0;
}
