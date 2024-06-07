// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Main program file for Project 2

#include "Code.h"

void findMatches(const dictionary& dict, const Grid& grid) {
    vector<string> wordsFound;

    int size = grid.getSize();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            string word;
            // Horizontal
            for (int k = j; k < size; ++k) {
                word += grid.getLetter(i, k);
                if (dict.wordLookup(word)) {
                    wordsFound.push_back(word);
                }
            }
            word.clear();
            // Vertical
            for (int k = i; k < size; ++k) {
                word += grid.getLetter(k, j);
                if (dict.wordLookup(word)) {
                    wordsFound.push_back(word);
                }
            }
        }
    }

    printWordsFound(wordsFound);
}

void search() {
    string dictFile, gridFile;
    cout << "Enter the dictionary file name: ";
    cin >> dictFile;
    cout << "Enter the grid file name: ";
    cin >> gridFile;

    dictionary dict(dictFile);
    Grid grid(10);
    grid.loadFromFile(gridFile);

    findMatches(dict, grid);
}

void search(int algorithm) {
    string dictFile, gridFile;
    cout << "Enter the dictionary file name: ";
    cin >> dictFile;
    cout << "Enter the grid file name: ";
    cin >> gridFile;

    dictionary dict(dictFile);
    if (algorithm == 1) {
        dict.quicksort(0, dict.words.size() - 1);
    } else if (algorithm == 2) {
        dict.heapsort();
    }

    Grid grid(10);
    grid.loadFromFile(gridFile);

    findMatches(dict, grid);
}

void printWordsFound(vector<string>& wordsFound) {
    cout << "Words found: " << endl;
    for (const string& word : wordsFound) {
        cout << word << endl;
    }
}

int main() {
    int choice;
    cout << "Enter 1 for quicksort, 2 for heapsort, or any other number to skip sorting: ";
    cin >> choice;
    search(choice);
    return 0;
}
