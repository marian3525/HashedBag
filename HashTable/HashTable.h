#pragma once

class HashTable {
public:
    explicit HashTable(unsigned int cap);

    void add(const int &elem);

    void remove(const int &elem);

    int *getAll(int &noOfElems) const;

    bool search(const int &elem) const;

    unsigned int size;      //number of elems in the hashtable
    int *elems = nullptr;
    unsigned int totalLen; //length of the table (hashing space length + collision space length)

private:
    unsigned int hash(const int &elemToHash) const;

    void updateNextFree();

    void debugPrint();

    void resize();

    unsigned int hashingLen;
    int *next = nullptr;
    unsigned int nextFree;
};
