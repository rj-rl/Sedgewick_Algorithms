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

bool DisjointSet::connected(size_t p, size_t q) const {
    auto pID = find(p);
    auto qID = find(q);
    return pID == qID;
}

void DisjointSet::unify(size_t p, size_t q) {
    auto pID = find(p);
    auto qID = find(q);
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
