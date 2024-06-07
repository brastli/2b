// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Header file Code.h. Contains class definitions for dictionary, grid

#ifndef EECE2560_PROJECT2_CODE_H
#define EECE2560_PROJECT2_CODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "d_matrix.h"
#include "heap.h"
#include "d_except.h"

using namespace std;

class dictionary {
private:
    vector<string> wordList; // Stores the words read from the file
    vector<string> words; // Stores words of length >= 5 for the project

public:
    // Reads words from the specified file and stores them in wordList
    void readWords(const string& file);

    // Outputs the list of words to the given output stream
    friend ostream& operator<<(ostream& os, const dictionary& dict);

    // Sorts the list of words in wordList
    void sortWords();

    // Checks if a given word exists in the wordList
    bool wordLookup(const string& word) const;

    // Constructor that reads words from a file and stores words with length >= 5
    dictionary(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string word;
            while (getline(file, word)) {
                if (word.length() >= 5) {
                    words.push_back(word);
                }
            }
            file.close();
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    // Sorts the word list using the quicksort algorithm
    void quicksort(int left, int right);

    // Sorts the word list using the heapsort algorithm
    void heapsort();
};

// The Grid class represents a 2D grid of characters and provides functionalities
// to load the grid from a file and access its elements.
class Grid {
private:
    matrix<char> grid; // 2D matrix to store the grid characters
    int size; // Size of the grid (assumed to be square)

public:
    // Constructor to initialize the grid with given size
    Grid(int n);

    // Loads the grid characters from the specified file
    void loadFromFile(const string& file);

    // Returns the character at the specified row and column in the grid
    char getLetter(int i, int j) const;

    // Returns the size of the grid
    int getSize() const;
};

// Finds and prints words from the dictionary that are present in the grid
void findMatches(const dictionary& dict, const Grid& grid);

// Handles user input and initiates the search process
void search();

// Overloaded search function that sorts the dictionary using the specified algorithm
void search(int algorithm);

// Prints the found words
void printWordsFound(vector<string>& wordsFound);

#endif  // EECE2560_PROJECT2_CODE_H
