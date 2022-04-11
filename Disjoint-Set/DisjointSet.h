#include <vector>

class DisjointSet {
public:
    DisjointSet(std::size_t size)
        : id_(size)
        , size_(size)
        , count_(size)
    {
        for (std::size_t i = 0; i < size; ++i) {
            id_[i] = i;
            size_[i] = 1;
        }
    }

    // returns number of components
    std::size_t count() const;
    // returns component id for site 'p'
    std::size_t find(std::size_t p) const;
    // returns true if 'p' and 'q' are in the same component
    std::size_t find_with_compression(std::size_t p);
    // same as regular 'find' but compresses the path travelled
    bool        connected(std::size_t p, std::size_t q) const;
    // connects sites 'p' and 'q'
    void        unify(std::size_t p, std::size_t q);

private:
    std::vector<std::size_t> id_;    // site-indexed components
    std::vector<std::size_t> size_;  // sizes of trees
    std::size_t count_;              // number of components
};
