//
// Created by Marian on 5/20/2018.
//

#ifndef HASHEDBAG_TABLEITERATOR_H
#define HASHEDBAG_TABLEITERATOR_H


#include "HashTable.h"

class TableIterator {
public:
    explicit TableIterator(HashTable& hashTable);
    ~TableIterator();
    void next();
    bool valid();
    int getCurrent();
private:
    int current;
    int index;
    HashTable* hashTable;
};


#endif //HASHEDBAG_TABLEITERATOR_H
