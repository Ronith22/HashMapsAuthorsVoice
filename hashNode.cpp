// CISC220: Ronith Anchan
// ranchan@udel.edu
#include "hashNode.hpp"
#include <cstdlib> 
#include <ctime> 

// Default constructor
hashNode::hashNode() {
    keyword = "";
    values = nullptr;
    valuesSize = 0;
    currSize = 0;
}


hashNode::hashNode(string s) {
    keyword = s;
    valuesSize = 100; 
    currSize = 0;
    values = new string[valuesSize]; 
}


hashNode::hashNode(string s, string v) {
    keyword = s;
    valuesSize = 100; 
    currSize = 1; 
    values = new string[valuesSize]; 
    values[0] = v; 
}

void hashNode::addValue(string v) {
    if (currSize >= valuesSize) {
        dblArray(); 
    }
    values[currSize] = v; 
    currSize++; 
}

void hashNode::dblArray() {
    valuesSize *= 2; 
    string* newArray = new string[valuesSize];
    for (int i = 0; i < currSize; i++) {
        newArray[i] = values[i]; 
    }
    delete[] values; 
    values = newArray; 
}

string hashNode::getRandValue() {
    if (currSize == 0) {
        return ""; 
    }
    int randomIndex = rand() % currSize; 
    return values[randomIndex]; 
}
