#include <iostream>
#include "HashTable.h"

#define null -1

HashTable::HashTable(unsigned int cap) {
    totalLen = cap;
    hashingLen = static_cast<unsigned int>(0.75 *
                                           cap);         //75% of the space used for hashing, 25% reserved for solving collisions
    nextFree = totalLen - 1;
    size = 0;

    elems = new int[totalLen];
    next = new int[totalLen];

    //init the arrays
    for (int i = 0; i < totalLen; i++) {
        elems[i] = null;
    }

    for (int i = 0; i < totalLen; i++) {
        next[i] = -1;
    }
    //debugPrint();
}

HashTable::~HashTable() {

}

void HashTable::debugPrint() {
    for(int i=0; i<totalLen; i++) {
        std::cout<<i<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"elems:"<<std::endl;
    for(int i=0; i<totalLen; i++) {
        std::cout<<elems[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"next:"<<std::endl;
    for(int i=0; i<totalLen; i++) {
        std::cout<<next[i]<<" ";
    }
    std::cout<<std::endl<<"--------------------------------------------------------"<<std::endl;
}
void HashTable::add(const int &elem) {
    /**
     * IN: elem: element to be added in the bag
     */
    if(size>=hashingLen-1) {
        resize();
    }

    int key = hash(elem);

    if (elems[key] == null) {
        //not used yet, add the elems
        elems[key] = elem;
        size++;
        updateNextFree(); //?
    } else {
        //hash collision, add the element to pos. nextFree and set the links
        int last = next[key];
        if(last != -1)
            while (next[last] != -1) {
                last = next[last];
            }
        else {
            last = key;
        }
        //last is the index of the last elem in the chain
        elems[nextFree] = elem;         //set elem
        next[last] = nextFree;          //link it to the chain
        size++;
        updateNextFree();
    }
    //debugPrint();
}

void HashTable::remove(const int &elem) {
    /**
     * Removes one instance of elem from the table
     * elem: int to be removed
     * Does nothing if elem is not in the hashtable
     */
     int key = hash(elem);
     if(elems[key] == null) {
         //elem is not in the table, don't do anything
         return;
     }
     if(elems[key] == elem) {
         //the head of the list has to be removed
         int nextElem;
         int nextNext;
         if(next[key]==-1) {
             //it is alone in the chain, simply delete it
             elems[key] = null;
             size--;
             return;
         }
         else {
             //it has other elements linked to it
             //save the 2nd in the chain and remove it
             nextElem=elems[next[key]];
             nextNext=next[next[key]];
             elems[next[key]] = null;
             next[next[key]] = null;
             //set the second in the position of the head
             elems[key] = nextElem;
             next[key] = nextNext;
             size--;
             return;
         }
     }
     else {
         //it is not the head of the chain, look for it
         int prevIdx;
         int nextIdx;

         prevIdx = key;
         nextIdx = next[key];
         while (next[key] != null) {
             if (elems[nextIdx] == elem) {
                 //found it, remove and set links
                 elems[nextIdx] = null;
                 next[prevIdx] = next[nextIdx]; //if null it is ok
                 size--;
                 return;
             }
             key = next[key];
             prevIdx = key;
             nextIdx = next[key];

         }
     }
}

int* HashTable::getAll(int &noOfElems) const {
    /**
     * OUT: a pointer to an array of noOfElems elements containing all the elements in the bag
     */
    int* all = new int[size];
    int k=0;

    for(int i=0; i<totalLen; i++) {
        if(elems[i] != null) {
            all[k++] = elems[i];
        }
    }
    noOfElems = k;
    return all;
}

unsigned int HashTable::hash(const int &elemToHash) const {
    return elemToHash%hashingLen;
}

bool HashTable::search(const int &elem) const {
    /**
     * IN: elem: the element to be searched
     * OUT: true if elem was found in the bag, false otherwise
     */
    int key = hash(elem);
    if(elems[key]==null) {
        return false;
    }
    else {
        if(elems[key]==elem) {
            return true;
        }

        while(next[key] != -1) {
            key = next[key];
            if(elems[key] == elem) {
                return true;
            }
        }
        return false;
    }
}

void HashTable::updateNextFree() {
    /**
     * Keep track of the next free position
     */
    unsigned int pos = totalLen - 1;

    while (elems[pos] != null) {
        pos--;
    }
    nextFree = pos;
}

void HashTable::resize() {
    /**
     * Resize the table to make room for more collisions
     * Allocate memory, rehash and add all the elements into the new space (doubled)
     */
    int* newElems = new int[2*totalLen];
    int* newNext = new int[2*totalLen];
    int newNextFree = 2*totalLen-1;

    for (int i = 0; i < totalLen*2; i++) {
        newElems[i] = null;
    }

    for (int i = 0; i < totalLen*2; i++) {
        newNext[i] = null;
    }

    hashingLen = static_cast<unsigned int>(0.75 * 2 *totalLen);

    //add all elements into the new memory space
    int n;
    int* all = getAll(n);
    for(int i=0; i<n; i++) {
        int elem = all[i];

        int key = hash(elem);
        if (newElems[key] == null) {
            //not used yet, add the elems
            newElems[key] = elem;
        } else {
            //hash collision, add the element to pos. nextFree and set the links
            int last = newNext[key];
            if(last != -1)
                while (newNext[last] != -1) {
                    last = newNext[last];
                }
            else {
                last = key;
            }
            //last is the index of the last elem in the chain
            newElems[newNextFree] = elem;         //set elem
            newNext[last] = newNextFree;          //link it to the chain

            //update next free
            unsigned int pos = 2*totalLen - 1;

            while (newElems[pos] != null) {
                pos--;
            }
            newNextFree = pos;
        }
    }
    elems = newElems;
    next = newNext;
    totalLen*=2;
}