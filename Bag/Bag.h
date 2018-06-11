#pragma once

#include "../HashTable/HashTable.h"

class Bag {
public:
    Bag();
    void add(const int& elem);
    void remove(const int& elem);
    bool isEmpty() const;
    void clear();
    int size() const;
    bool exists(const int& elem) const;
private:
    HashTable hashTable{23};
    friend class BagIterator;

};