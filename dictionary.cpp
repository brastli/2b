// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// File contains functions for readWords, an operator overload for <<,
// sortWords, wordLookup, loadFromFile, getLetter, getSize, findMatches, and search

#include "Code.h"

// Reads words from the specified file and adds words of length >= 5 to wordList
void dictionary::readWords(const string& file) {
    ifstream inFile(file);
    if (!inFile) {
        throw fileOpenError(file); // Throw an error if the file cannot be opened
    }
    string word;
    while (inFile >> word) {
        if (word.length() >= 5) {
            wordList.push_back(word); // Add words of length >= 5 to wordList
        }
    }
    inFile.close();
}

// Overloaded output stream operator to print the dictionary word list
ostream& operator<<(ostream& os, const dictionary& dict) {
    for (const string& word : dict.wordList) {
        os << word << endl; // Print each word in wordList
    }
    return os;
}

// Sorts the wordList using the standard library sort function
void dictionary::sortWords() {
    sort(wordList.begin(), wordList.end());
}

// Checks if the specified word exists in the sorted wordList using binary search
bool dictionary::wordLookup(const string& word) const {
    return binary_search(wordList.begin(), wordList.end(), word);
}

// Sorts the wordList using the quicksort algorithm
void dictionary::quicksort(int left, int right) {
    if (left < right) {
        int i = left, j = right;
        string pivot = wordList[(left + right) / 2]; // Choose the middle element as the pivot
        while (i <= j) {
            while (wordList[i] < pivot) i++; // Find an element larger than or equal to pivot
            while (wordList[j] > pivot) j--; // Find an element smaller than or equal to pivot
            if (i <= j) {
                swap(wordList[i], wordList[j]); // Swap elements to partition the list
                i++;
                j--;
            }
        }
        quicksort(left, j); // Recursively sort the left partition
        quicksort(i, right); // Recursively sort the right partition
    }
}

// Sorts the wordList using the heapsort algorithm
void dictionary::heapsort() {
    heap<string> h;
    for (const string& word : wordList) {
        h.insert(word); // Insert all words into the heap
    }
    h.initializeMaxHeap(); // Initialize the max-heap
    wordList.clear(); // Clear the original wordList
    while (h.size() > 0) {
        wordList.push_back(h.extractMax()); // Extract max elements from the heap and append to wordList
    }
}
