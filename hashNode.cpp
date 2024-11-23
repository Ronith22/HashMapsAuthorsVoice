// CISC220: Ansh Desai and Sara Rathore
// adesai@udel.edu, srathor@udel.edu
#include "hashNode.hpp"
#include <cstdlib> // for rand()
#include <ctime> // for seeding rand()

// Default constructor
hashNode::hashNode() {
    keyword = "";
    values = nullptr;
    valuesSize = 0;
    currSize = 0;
}

// Constructor with keyword
hashNode::hashNode(string s) {
    keyword = s;
    valuesSize = 100; // Initial size for the values array
    currSize = 0;
    values = new string[valuesSize]; // Dynamically allocate array
}

// Constructor with keyword and initial value
hashNode::hashNode(string s, string v) {
    keyword = s;
    valuesSize = 100; // Initial size for the values array
    currSize = 1; // Since we're adding one value
    values = new string[valuesSize]; // Dynamically allocate array
    values[0] = v; // Add the initial value
}

// Adds a new value to the array
void hashNode::addValue(string v) {
    if (currSize >= valuesSize) {
        dblArray(); // Double the array if there's no space
    }
    values[currSize] = v; // Add the value to the end
    currSize++; // Increment the size
}

// Doubles the size of the array
void hashNode::dblArray() {
    valuesSize *= 2; // Double the size
    string* newArray = new string[valuesSize]; // Create a new array
    for (int i = 0; i < currSize; i++) {
        newArray[i] = values[i]; // Copy over the old values
    }
    delete[] values; // Delete the old array
    values = newArray; // Point to the new array
}

// Returns a random string from the values array
string hashNode::getRandValue() {
    if (currSize == 0) {
        return ""; // Return empty string if no values
    }
    int randomIndex = rand() % currSize; // Get a random index
    return values[randomIndex]; // Return the value at that index
}
