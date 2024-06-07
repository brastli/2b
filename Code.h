// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Header file Code.h. Contains class definitions for dictionary, grid, and the
// global functions findMatches and search

#ifndef EECE2560_PROJECT2_CODE_H
#define EECE2560_PROJECT2_CODE_H

#include <iostream>
#include <string>
#include <vector>
#include "d_matrix.h"

using namespace std;

class dictionary {

private:
    
    vector<string> wordList;        // The list of words in the dictionary
    vector<string> words;           // Vector to store the words

public:

    // Takes an txt file and reads each line into the wordList
    void readWords(const string& file);

    // Overloaded output operator to print the word list
    friend ostream& operator<<(ostream& os, const dictionary& words);

    // Sorts the words in the dictionary using selection sort
    void sortWords();

    // Handles word lookups using binary search
    bool wordLookup(const string& word) const;

     Dictionary(string filename) {
        ifstream file(filename); // Open the file
        if (file.is_open()) { // Check if the file is successfully opened
            string word;
            while (getline(file, word)) { // Read each word from the file
                if (word.length() >= 5) { // Check if the word length is at least 5
                    words.push_back(word); // Add the word to the list
                }
            }
            file.close(); // Close the file
        } else {
            cerr << "Unable to open file: " << filename << endl; // Error message if file cannot be opened
        }
    }

    // Public method to sort words using quicksort
    void quicksort(int left, int right) {
        if (left >= right) { // Base case: if the segment size is 1 or zero
            return;
        }
        // Choose pivot element
        string pivot = words[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            // Move left pointer to the right until an element >= pivot is found
            while (words[i] < pivot) {
                i++;
            }
            // Move right pointer to the left until an element <= pivot is found
            while (words[j] > pivot) {
                j--;
            }
            // Swap elements and move pointers inward
            if (i <= j) {
                swap(words[i], words[j]);
                i++;
                j--;
            }
        }
        // Recursively sort the left and right subarrays
        quicksort(left, j);
        quicksort(i, right);
};

class Grid {

private:

    matrix<char> grid;      // The grid matrix
    int size;               // The size of the n x n matrix

public:

    // Constructor
    Grid(int n);

    // Loads the grid from a file and stores it into a matrix
    void loadFromFile(const string& file);

    // Gets an individual character from the matrix
    char getLetter(int i, int j) const;

    // Returns the size of the grid
    int getSize() const;

};

// Global function that finds words from the grid that can be found in the dictionary
void findMatches(const dictionary& dict, const Grid& grid);

// Global function that reads the name of the grid file from the keyboard, reads data from the input files, and prints
// out candidate words
void search();

#endif
