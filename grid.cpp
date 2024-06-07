// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// File contains functions for Grid,
// loadFromFile, getLetter, getSize

#include "Code.h"

// Constructor to initialize the grid with given size n
Grid::Grid(int n) : grid(n, n), size(n) {}

// Function to load the grid from a file
void Grid::loadFromFile(const string& file) {
    ifstream inFile(file); // Open the file
    if (!inFile) {
        throw fileOpenError(file); // Throw an error if the file cannot be opened
    }
    char ch;
    // Read characters from the file into the grid
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> ch;
            grid[i][j] = ch; // Assign character to grid position (i, j)
        }
    }
    inFile.close(); // Close the file
}

// Function to get the letter at grid position (i, j)
char Grid::getLetter(int i, int j) const {
    // Check for valid indices
    if (i < 0 || i >= size || j < 0 || j >= size) {
        throw indexRangeError("Grid: invalid index", i, size); // Throw an error if indices are out of range
    }
    return grid[i][j]; // Return the character at position (i, j)
}

// Function to get the size of the grid
int Grid::getSize() const {
    return size;
}
