// CISC220: Ronith Anchan
// ranchan@udel.edu
#include "hashMap.hpp"
#include "hashNode.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {
    first = "";
    numKeys = 0;
    mapSize = 101; 
    h1 = hash1;
    c1 = coll1;
    collisionct1 = 0;
    collisionct2 = 0;
    map = new hashNode*[mapSize]; 
    for (int i = 0; i < mapSize; i++) {
        map[i] = nullptr; 
    }
}

void hashMap::addKeyValue(string k, string v) {
    int index = getIndex(k);
    if (map[index] == nullptr) { // Slot is empty
        map[index] = new hashNode(k, v);
        numKeys++;
    } else if (map[index]->keyword == k) { // Key exists
        map[index]->addValue(v);
    }


    if (1.0 * numKeys / mapSize > 0.7) {
        reHash();
    }
}

int hashMap::getIndex(string k) {
    int index;
    if (h1) {
        index = calcHash(k);
    } else {
        index = calcHash2(k);
    }
    int i = 0;

    if (map[index] != nullptr && map[index]->keyword != k) {
        collisionct1++;
    }

    while (map[index] != nullptr && map[index]->keyword != k) {
        collisionct2++; // Count secondary collision during probing
        if (c1) {
            index = collHash1(index, ++i, k);
        } else {
            index = collHash2(index, ++i, k);
        }

        index %= mapSize;
    }

    if (numKeys * 1.0 / mapSize > 0.7) {
        reHash();
        return getIndex(k);
    }

    return index;
}

// Hash function 1
int hashMap::calcHash(string k) {
    int hash = 0;
    for (int i = 0; i < k.length(); i++) {
        hash += (k[i] * (i + 1));
    }
    return abs(hash) % mapSize;
}

// Hash function 2
int hashMap::calcHash2(string k) {
    int hash = 0;
    int base = 5;
    for (int i = 0; i < k.length(); i++) {
        hash = (hash * base + (int)k[i]) % mapSize;
    }

    return abs(hash);
}

// Collision handling method 1
int hashMap::collHash1(int h, int i, string k) {
    return (h + i) % mapSize;
}

// Collision handling method 2
int hashMap::collHash2(int h, int i, string k) {
    return (h + i * i) % mapSize;
}

// Rehash the hash map
void hashMap::reHash() {
    int oldSize = mapSize;
    mapSize *= 2;
    getClosestPrime();
    hashNode** oldMap = map;
    map = new hashNode*[mapSize];
    for (int i = 0; i < mapSize; i++) {
        map[i] = nullptr;
    }
    numKeys = 0;
     for (int i = 0; i < oldSize; i++) {
        if (oldMap[i] != nullptr) {
            string key = oldMap[i]->keyword;
            for (int j = 0; j < oldMap[i]->currSize; j++) {
                addKeyValue(key, oldMap[i]->values[j]);  // Reinsert each value
            }
            delete oldMap[i];  // Delete the old node
        }
    }
    delete[] oldMap;
}

// Find the closest prime number for map resizing
void hashMap::getClosestPrime() {
    int candidate = mapSize;
    bool isPrime = false;
     while (!isPrime) {
        isPrime = true;
        for (int i = 2; i <= sqrt(candidate); i++) {
            if (candidate % i == 0) {
                isPrime = false;
                candidate++;
                break;
            }
        }
    }
    mapSize = candidate;
}

// Find the index of a key
int hashMap::findKey(string k) {
    int index;
    if (h1){
        index = calcHash(k);
    } else {
        index = calcHash2(k);
    }
    int i = 0;
    while (map[index] != nullptr) {
        if (map[index]->keyword == k) {
            return index; // key found
        }
        if (c1) {
            index = collHash1(index, ++i, k);
        } else {
            index = collHash2(index, ++i, k);
        }

        index %= mapSize;
    }
    return -1; // key not found
}

// Print the hash map
void hashMap::printMap() {
    for (int i = 0; i < mapSize; i++) {
        if (map[i] != nullptr) {
            cout << "Index " << i << ": Key = \"" << map[i]->keyword << "\", Values = [";

            for (int j = 0; j < map[i]->currSize; j++) {
                cout << map[i]->values[j];
                if (j < map[i]->currSize - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        } else {
            cout << "Index " << i << ": Empty" << endl;
        }
    }
}
