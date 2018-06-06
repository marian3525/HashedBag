//
// Created by Marian on 5/20/2018.
//

#ifndef HASHEDBAG_BAGITERATOR_H
#define HASHEDBAG_BAGITERATOR_H

#include "../HashTable/TableIterator.h"
#include "Bag.h"

class BagIterator {

public:
    explicit BagIterator(Bag& b);
    void next();
    int getCurrent();
    bool valid();
private:
    TableIterator* tableIterator;
};
#endif //HASHEDBAG_BAGITERATOR_H