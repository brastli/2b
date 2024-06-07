// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Main program file for Project 2

#include <iostream>
#include "Code.h"

using namespace std;

int main() {

    // Searches for words in the grid that match those in the dictionary
    search();
    Dictionary dict("dictionary.txt"); // Create a Dictionary object with the filename
    dict.quicksort(0, dict.words.size() - 1); // Sort the words using quicksort
    // Print the sorted words
    for (auto word : dict.words) {
        cout << word << endl;
    }
    // Prompt the user to choose the sorting algorithm
    int algorithm;
    cout << "Enter 1 for quicksort, 2 for heapsort: ";
    cin >> algorithm;

    // Perform the search with the chosen algorithm
    search(algorithm);
    return 0;

}
