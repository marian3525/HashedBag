//
// Created by Marian on 5/20/2018.
//

#include "TableIterator.h"

TableIterator::TableIterator(HashTable& hashTable) {
    this->hashTable = &hashTable;

    index = this->hashTable->totalLen-1;

    //find the first non null element and set the positin to it
    while(index >= 0) {
        if(this->hashTable->elems[index] != -1) {
            break;
        }
        index--;
    }
    //if reached the end before finding something non null
    if(index == -1) {
        current = -1;
    }
    else{  //it exited with break, the first non null elem is at position index
        current = this->hashTable->elems[index];
    }
}

void TableIterator::next() {
    index--;
    while(index >= 0) {     //
        if(hashTable->elems[index] != -1) {
            break;
        }
        index--;
    }
    if(index == -1) {
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
