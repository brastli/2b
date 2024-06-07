// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Main program file for Project 2


#include "Code.h"

// Function to find and print words from the dictionary that are present in the grid
void findMatches(const dictionary& dict, const Grid& grid) {
    vector<string> wordsFound; // Vector to store the found words

    int size = grid.getSize(); // Get the size of the grid
    // Loop through each cell of the grid
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            string word;

            // Check for horizontal words starting at (i, j)
            for (int k = j; k < size; ++k) {
                word += grid.getLetter(i, k);
                if (dict.wordLookup(word)) {
                    wordsFound.push_back(word);
                }
            }
            word.clear();

            // Check for vertical words starting at (i, j)
            for (int k = i; k < size; ++k) {
                word += grid.getLetter(k, j);
                if (dict.wordLookup(word)) {
                    wordsFound.push_back(word);
                }
            }
        }
    }

    printWordsFound(wordsFound); // Print the found words
}

// Function to handle user input and initiate the search process without sorting
void search() {
    string dictFile, gridFile;
    cout << "Enter the dictionary file name: ";
    cin >> dictFile;
    cout << "Enter the grid file name: ";
    cin >> gridFile;

    dictionary dict(dictFile); // Create a dictionary object and load words from the file
    Grid grid(10); // Create a grid object with size 10
    grid.loadFromFile(gridFile); // Load the grid from the file

    findMatches(dict, grid); // Find and print the matching words
}

// Overloaded search function to handle user input and initiate the search process with sorting
void search(int algorithm) {
    string dictFile, gridFile;
    cout << "Enter the dictionary file name: ";
    cin >> dictFile;
    cout << "Enter the grid file name: ";
    cin >> gridFile;

    dictionary dict(dictFile); // Create a dictionary object and load words from the file
    // Sort the dictionary using the specified algorithm
    if (algorithm == 1) {
        dict.quicksort(0, dict.words.size() - 1); // Sort using quicksort
    } else if (algorithm == 2) {
        dict.heapsort(); // Sort using heapsort
    }

    Grid grid(10); // Create a grid object with size 10
    grid.loadFromFile(gridFile); // Load the grid from the file

    findMatches(dict, grid); // Find and print the matching words
}

// Function to print the found words
void printWordsFound(vector<string>& wordsFound) {
    cout << "Words found: " << endl;
    for (const string& word : wordsFound) {
        cout << word << endl; // Print each found word
    }
}

// Main function to handle user input and initiate the search with or without sorting
int main() {
    int choice;
    cout << "Enter 1 for quicksort, 2 for heapsort, or any other number to skip sorting: ";
    cin >> choice;
    search(choice); // Call the search function with the user's choice of sorting algorithm
    return 0;
}
