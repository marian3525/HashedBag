#pragma once

class HashTable {
public:
    HashTable(unsigned int cap);

    ~HashTable();

    void add(const int &elem);

    void remove(const int &elem);

    int *getAll(int &noOfElems) const;

    bool search(const int &elem) const;

    unsigned int size;
    int *elems = nullptr;
    unsigned int totalLen;

private:
    unsigned int hash(const int &elemToHash) const;

    void updateNextFree();

    void debugPrint();

    void resize();

    unsigned int hashingLen;
    int *next = nullptr;
    unsigned int nextFree;
};
