//
// Created by Marian on 5/20/2018.
//

#include "BagIterator.h"

BagIterator::BagIterator(Bag& bag) {
    this->tableIterator = new TableIterator(bag.hashTable);
}

void BagIterator::next() {
    tableIterator->next();
}

int BagIterator::getCurrent() {
    return tableIterator->getCurrent();
}

bool BagIterator::valid() {
    return tableIterator->valid();
}
