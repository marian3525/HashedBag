#pragma once

#include "../HashTable/HashTable.h"

class Bag {
public:
    Bag();
    ~Bag();
    void add(const int& elem);
    void remove(const int& elem);
    bool isEmpty() const;
    void clear();
    int size() const;
    int exists(const int& elem) const;
    HashTable hashTable{23};

};