//
// Created by Marian on 5/20/2018.
//

#include "TableIterator.h"

TableIterator::TableIterator(HashTable& hashTable) {
    index = 0;
    this->hashTable = &hashTable;
    while(index < this->hashTable->totalLen) {
        if(this->hashTable->elems[index] != -1) {
            break;
        }
        index++;
    }
    if(index == this->hashTable->totalLen) {
        current = -1;
    }
    else{
        current = this->hashTable->elems[index];
    }
}

void TableIterator::next() {
    index++;
    while(index < hashTable->totalLen) {
        if(hashTable->elems[index] != -1) {
            break;
        }
        index++;
    }
    if(index == hashTable->totalLen) {
        current = -1;
    }
    else{
        current = hashTable->elems[index];
    }
}

bool TableIterator::valid() {
    return index < hashTable->totalLen and current != -1;
}

int TableIterator::getCurrent() {
    return current;
}

TableIterator::~TableIterator() {

}
