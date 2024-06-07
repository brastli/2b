// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Header file Code.h. Contains class definitions for dictionary, grid, and the
// global functions findMatches and search

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
    vector<string> wordList;
    vector<string> words;

public:
    void readWords(const string& file);
    friend ostream& operator<<(ostream& os, const dictionary& dict);
    void sortWords();
    bool wordLookup(const string& word) const;

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

    void quicksort(int left, int right);
    void heapsort();
};

class Grid {
private:
    matrix<char> grid;
    int size;

public:
    Grid(int n);
    void loadFromFile(const string& file);
    char getLetter(int i, int j) const;
    int getSize() const;
};

void findMatches(const dictionary& dict, const Grid& grid);
void search();
void search(int algorithm);
void printWordsFound(vector<string>& wordsFound);

#endif	// EECE2560_PROJECT2_CODE_H
