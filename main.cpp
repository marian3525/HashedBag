#include <iostream>
#include "HashTable/HashTable.h"
#include "HashTable/TableIterator.h"
#include "Bag/BagIterator.h"
#include "Tests/Tester.h"

using namespace std;
int main() {
    Tester tester{};
    tester.test();

    string word1, word2;
    cin>>word1>>word2;
    Bag bag1{};
    Bag bag2{};

    for(auto letter: word1) {
        bag1.add((int) letter);
    }

    for(auto letter: word2) {
        bag2.add((int) letter);
    }

    BagIterator it{bag1};

    while(it.valid()) {
        bag2.remove(it.getCurrent());
        it.next();
    }

    (bag2.isEmpty())?cout<<"Anagrams":cout<<"Not anagrams";

    return 0;

}