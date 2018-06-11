#include <iostream>
#include "HashTable/HashTable.h"
#include "HashTable/TableIterator.h"
#include "Bag/BagIterator.h"
#include "Tests/Tester.h"
using namespace std;

void test() {
    Tester test{};
    test.test();
}

void solve(string word1, string word2) {
    Bag bag1{};
    Bag bag2{};

    //add the letters from the 2 words in 2 bags
    for(auto letter: word1) {
        bag1.add((int) letter);
    }

    for(auto letter: word2) {
        bag2.add((int) letter);
    }

    BagIterator it{bag1};
    //remove the letters found in the first word from the second word
    //if after these removals the second word bag is empty, the words were anagrams of each other
    while(it.valid()) {
        char c = (char) it.getCurrent();
        if(bag2.exists(c))      //the case s1:"anna", s2:"ana"
            bag2.remove(c);
        else {
            cout << "Not anagrams";
            return;
        }
        it.next();
    }

    if(bag2.isEmpty())
        cout<<"Anagrams";
    else
        cout<<"Not anagrams";
}

int main() {

    string word;
    cout<<"Enter the first word:";
    cin>>word;

    Bag bag1{};
    char el;
    int counter = 0;
    cout<<"Enter the elem to search:";
    cin>>el;
    int elem = (int) el;

    //add the letters from the 2 words in 2 bags
    for(auto letter: word) {
        bag1.add((int) letter);
    }

    BagIterator bagIt{bag1};

    while(bagIt.valid()) {
        if(bag1.exists(elem)) {
            bag1.remove(elem);
            counter++;
        }
        bagIt.next();
    }

    cout<<"ELem: '"<<el<<"' appears "<<counter<<" times";

    return 0;

}