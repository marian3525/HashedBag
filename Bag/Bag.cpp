#include "Bag.h"

Bag::Bag() {
    hashTable = HashTable{23};
}

void Bag::add(const int &elem) {
    /**
     * IN: elem: element to add to the bag
     */
     hashTable.add(elem);
}

void Bag::remove(const int &elem) {
    /**
     * IN: elem: element to remove, doesn;t have to be in the bag
     */
     hashTable.remove(elem);
}

bool Bag::exists(const int &elem) const {
    /**
     * IN: elem: int
     * OUT: true if elem is in the bag, false otherwise
     */
    return hashTable.search(elem);
}

bool Bag::isEmpty() const {
    /**
     * Returns true if the bag has no elems, false otherwise
     */
    return hashTable.size == 0;
}

void Bag::clear() {
    /**
     * Removes all elements from the bag3
     */
    int n;
    int* all = hashTable.getAll(n);
    for(int i=0; i<n; i++) {
        hashTable.remove(all[i]);
    }
}
int Bag::size() const {
    return hashTable.size;
}