// Ronith Anchan
// ranchan@udel.edu
#include "makeSeuss.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    string inputFile = "DrSeuss.txt";

    string outputFile1 = "output_hash1_coll1.txt";
    string outputFile2 = "output_hash1_coll2.txt";
    string outputFile3 = "output_hash2_coll1.txt";
    string outputFile4 = "output_hash2_coll2.txt";

    // hash function 1 and collision method 1
    makeSeuss seuss1(inputFile, outputFile1, true, true);

    // hash function 1 and collision method 2
    makeSeuss seuss2(inputFile, outputFile2, true, false);

    // hash function 2 and collision method 1
    makeSeuss seuss3(inputFile, outputFile3, false, true);

    // hash function 2 and collision method 2
    makeSeuss seuss4(inputFile, outputFile4, false, false);

    return 0;
}
