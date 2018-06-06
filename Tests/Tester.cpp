#include <assert.h>
#include "Tester.h"
#include "../Bag/Bag.h"
#include "../Bag/BagIterator.h"

void Tester::test() {
    testBag();
    testBagIterator();

    testHashTable();
    testTableIterator();
}

void Tester::testBag() {
    Bag bag{};
    assert(bag.size() == 0);
    assert(bag.isEmpty() == true);

    bag.add(0);
    assert(bag.isEmpty() == false);
    assert(bag.exists(12) == false);

    bag.add(12);
    assert(bag.exists(12) == true);

    bag.add(22);
    bag.add(22);
    bag.add(0);
    bag.add(13);
    bag.add(10);
    bag.add(12);

    assert(bag.size() == 8);
    assert(bag.isEmpty() == false);
    assert(bag.exists(22) == true);
    assert(bag.exists(1) == false);
    assert(bag.exists(2) == false);

    bag.remove(0);
    assert(bag.exists(0) == true);
    assert(bag.size() == 7);

    bag.remove(0);
    assert(bag.exists(0) == false);
    assert(bag.size() == 6);

    bag.clear();
    assert(bag.isEmpty() == true);
    assert(bag.size() == 0);
    assert(bag.exists(13) == false);
}

void Tester::testHashTable() {
    unsigned int capacity = 2;
    HashTable table{capacity};
    assert(table.size == 0);
    assert(table.totalLen == capacity);
    assert(table.elems != nullptr);

    table.add(0);
    assert(table.size == 1);
    assert(table.search(0)==true);
    assert(table.search(12) == false);

    table.add(12);
    assert(table.size == 2);
    assert(table.search(0)==true);
    assert(table.search(12) == true);

    table.add(40);
    table.add(23);
    table.add(40);
    assert(table.size == 5);
    assert(table.search(40) == true);
    assert(table.search(23) == true);
    assert(table.search(20) == false);

    table.remove(23);
    assert(table.size == 4);
    assert(table.search(40) == true);
    assert(table.search(23) == false);

    table.remove(40);
    assert(table.size == 3);
    assert(table.search(40)== true);
    table.remove(40);
    assert(table.size == 2);
    assert(table.search(40) == false);

    assert(table.search(10) ==  false);
}

void Tester::testBagIterator() {
    Bag bag{};
    bag.add(0);
    bag.add(12);
    bag.add(12);
    bag.add(20);
    bag.add(23);
    bag.add(40);
    bag.add(12);
    bag.add(29);

    BagIterator bagIterator{bag};

    while(bagIterator.valid()) {
        int current = bagIterator.getCurrent();
        assert(current == 0 or current == 12 or current == 20 or current == 23 or current == 40 or current == 29);
        bagIterator.next();
    }
}

void Tester::testTableIterator() {
    HashTable table{23};
    table.add(0);
    table.add(12);
    table.add(12);
    table.add(20);
    table.add(23);
    table.add(40);
    table.add(12);
    table.add(29);

    TableIterator tableIterator{table};

    while(tableIterator.valid()) {
        int current = tableIterator.getCurrent();
        assert(current == 0 or current == 12 or current == 20 or current == 23 or current == 40 or current == 29);
        tableIterator.next();
    }
}
