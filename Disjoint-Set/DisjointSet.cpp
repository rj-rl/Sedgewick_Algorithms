#include "DisjointSet.h"

using namespace std;

size_t DisjointSet::count() const {
    return count_;
}

size_t DisjointSet::find(size_t p) const {
    while (id_[p] != p) {
        p = id_[p];
    }
    return p;
}

size_t DisjointSet::find_with_compression(size_t p)
{
    // find the root, i.e. the component id for p
    auto root = p;
    while (id_[root] != root) {
        root = id_[root];
    }
    // path compression: point all links on the way directly to component's root
    // which reduces the tree's height
    while (id_[p] != p) {
        auto old_parent = id_[p];
        id_[p] = root;
        p = old_parent;
    }
    return p;
}

bool DisjointSet::connected(size_t p, size_t q) const {
    auto pID = find(p);
    auto qID = find(q);
    return pID == qID;
}

void DisjointSet::unify(size_t p, size_t q) {
    auto pID = find_with_compression(p);
    auto qID = find_with_compression(q);
    if (pID == qID) return;

    if (size_[pID] < size_[qID]) {
        id_[pID] = qID;
        size_[qID] += size_[pID];
    }
    else {
        id_[qID] = pID;
        size_[pID] += size_[qID];
    }
    // two components are merging together, decrease the count
    --count_;
}
