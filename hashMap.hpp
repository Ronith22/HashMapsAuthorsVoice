#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include "hashNode.hpp"
#include <string>

using namespace std;

class hashMap {
    friend class makeSeuss;
    hashNode **map;
    string first;
    int numKeys;
    int mapSize;
    bool h1;
    bool c1;
    int collisionct1;
    int collisionct2;

public:
    hashMap(bool hash1, bool coll1);
    void addKeyValue(string k, string v);
    // adds a node to the map at the correct index based on the key string, and then inserts the value into the value field of the hashNode
    // Must check to see whether there's a node at that location. If there's nothing there (it's NULL), add the hashNode with the keyword and value.
    // If the node has the same keyword, just add the value to the list of values.
    //If the node has a different keyword, keep calculating a new hash index until either the keyword matches the node at that index's keyword, or until the
    // map at that index is NULL, in which case you'll add the node there.
    //This method also checks for load, and if the load is over 70%, it calls the reHash method to create a new longer map array and rehash the values
    //if h1 is true, the first hash function is used, and if it’s false, the second is used.
    //if c1 is true, the first collision method is used, and if it’s false, the second is used
    int getIndex(string k); // uses calcHash and reHash to calculate and return the index of where the keyword k should be inserted into the map array
    int calcHash(string k); // hash function
    int calcHash2(string k); // hash function 2

    void getClosestPrime(); // I used a binary search on an array of prime numbers to find the closest prime to double the map Size, and then set mapSize to that new prime. You can include as one of the fields an array of prime numbers, or you can write a function that calculates the next prime number. Whichever you prefer.
    void reHash(); // when size of array is at 70%, double array size and rehash keys
    int collHash1(int h, int i, string k); // getting index with collision method 1 (note – you may modify the parameters if you don’t need some/need more)
    int collHash2(int h, int i, string k); // getting index with collision method 2 (note – you may modify the parameters if you don’t need some/need more)
    int findKey(string k); //finds the key in the array and returns its index. If it's not in the array, returns -1
    void printMap(); //I wrote this solely to check if everything was working. Its only purpose is for testing.
};

#endif