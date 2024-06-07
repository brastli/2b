// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// File contains functions for readWords, an operator overload for <<,
// sortWords, wordLookup, loadFromFile, getLetter, getSize, findMatches, and search

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Code.h"
using namespace std;

// Reads words from the dictionary file
void dictionary::readWords(const string& file)
{
    // Open the input file for reading
    ifstream f (file);

    // Variable to read each line in file
    string line;

    // Check if the file is open
    if (f.is_open())
    {
        // Read each line in the file
        while (getline(f, line))
        {
            // Stores each word in the word list vector
            wordList.push_back(line);
        }
        // Close the file
        f.close();
    }

        // Give an error if the file was not able to be opened
    else
    {
        cout << "file not found" << endl;
    }
}

// Prints word list vector from dictionary line by line
ostream& operator<<(ostream& os, const dictionary& dict)
{
    // Iterate through vector and prints each element on a new line
    for (auto & element : dict.wordList)
    {
        cout << element << endl;
    }
    return os;
}

// Sorts the words in the dictionary using selection sort
void dictionary::sortWords()
{
    // Get the size of the word vector
    int n = wordList.size();

    // Traverse through the vector
    for (int i = 0; i < n - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            // Update minIndex if the current element is smaller
            if (wordList[j] < wordList[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element
        if (minIndex != i)
        {
            swap(wordList[i], wordList[minIndex]);
        }
    }
}

// Function to handle word lookups using binary search
bool dictionary::wordLookup(const string& word) const
{
    int first = 0;                          // Left boundary
    int last = wordList.size() - 1;         // Right boundary

    while (first <= last) {

        // Get the middle index of the current range
        int mid = first + (last - first) / 2;

        // Check if the middle element is the word and return true if it is
        if (wordList[mid] == word) {
            return true;
        }
        // If the middle element is less than the word, move the search to the latter half
        else if (wordList[mid] < word) {
            first = mid + 1;
        }
        // If the middle element is greater than the word, move the search to the former half
        else {
            last = mid - 1;
        }
    }
    return false;
}

// Grid constructor
Grid::Grid(int n) : size(n), grid(n, n) {}

// Loads the grid from the file and stores it into a matrix
void Grid::loadFromFile(const string &file) {

    // Opens the file
    ifstream f (file);

    if (f.is_open()) {

        // Loop through each row of the grid
        for (int i = 0; i < size; i++) {

            // Loop through each column of the grid
            for (int j = 0; j < size; j++) {

                // Read a character from the file into the grid at (i, j)
                f >> grid[i][j];
            }
        }
        f.close();
    }
    else {
        cout << "Unable to open file: " << file << endl;
    }
}

// Gets an individual letter from the grid from its index
char Grid::getLetter(int i, int j) const{

    // Adjust the row and columns indices to wrap around
    i = (i + size) % size;
    j = (j + size) % size;

    // Return the character at the adjusted indices
    return grid[i][j];

}

// Returns the size of the grid
int Grid::getSize() const{
    return size;
}

// Finds words from the grid that can be found in the dictionary
void findMatches(const dictionary& dict, const Grid& grid) {

    // Get the size of the grid
    int size = grid.getSize();

    // Iterate through every letter in the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            // Iterate through every possible direction
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {

                    // Skip the direction (0, 0) because it does not represent a valid movement
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    // Iterate through word lengths from 5 to the maximum size of the grid
                    for (int len = 5; len <= size; len++) {
                        string word;

                        // Construct the word by iterating through letters in the current direction
                        for (int k = 0; k < len; k++) {

                            // Calculate the new coordinates, wrapping around the grid edges if necessary
                            int x = (i + k * dx + size) % size;
                            int y = (j + k * dy + size) % size;

                            // Add the letter at the calculated coordinates to the word
                            word += grid.getLetter(x, y);
                        }

                        // Check if the constructed word exists in the dictionary
                        if (dict.wordLookup(word)) {

                            // Print the word if it is found in the dictionary
                            cout << word << endl;
                        }
                    }
                }
            }
        }
    }
}

// Reads the name of the grid file from the keyboard, reads data from the input files, and prints out candidate words
void search()
{
    // Prompt the user to enter the name of the grid file
    string gridFilename;
    cout << "Enter the name of the grid file: ";
    cin >> gridFilename;

    // Extract the grid size from the file name
    string numString = gridFilename.substr(5, 2);

    // Convert the string to an integer
    int n = stoi(numString);
    cout << "The size of the grid is: " << n << endl;

    // Initialize the Grid object using the specified file and the known size of the grid
    // n is changed manually depending on grid size
    Grid grid(n);
    grid.loadFromFile(gridFilename);

    dictionary dict;
    dict.readWords("Dictionary");
    dict.sortWords();
    findMatches(dict, grid);
}

void dictionary::heapsort() {
    // Create a max heap using the words in the dictionary
    heap<string> max_heap;
    // Insert each word from the dictionary into the max heap
    for (const auto& word : words) {
        max_heap.insert(word);
    }
    // Build the max heap to ensure heap properties are satisfied
    max_heap.buildMaxHeap();

    // Sort the words in descending order
    // Extract the maximum element from the heap and place it at the end of the array
    for (int i = words.size() - 1; i >= 0; i--) {
        words[i] = max_heap.extractMax();
    }
}

void printWordsFound(vector<string>& wordsFound);

// Function to search for words in the grid
void search(int algorithm)
{
    // Prompt the user for the grid file name
    string gridFileName;
    cout << "Enter the name of the grid file: ";
    cin >> gridFileName;

    // Open the grid file
    ifstream gridFile(gridFileName);
    if (!gridFile) // Check if the file opened successfully
    {
        cout << "Error: unable to open grid file." << endl;
        return;
    }

    // Read the size of the grid
    int n;
    gridFile >> n;

    // Read the grid itself
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            gridFile >> grid[i][j];
        }
    }

    // Prompt the user for the word list file name
    string wordListFileName;
    cout << "Enter the name of the word list file: ";
    cin >> wordListFileName;

    // Open the word list file
    ifstream wordListFile(wordListFileName);
    if (!wordListFile) // Check if the file opened successfully
    {
        cout << "Error: unable to open word list file." << endl;
        return;
    }

    // Read the word list
    vector<string> wordList;
    string word;
    while (wordListFile >> word)
    {
        wordList.push_back(word);
    }

    // Create a dictionary object and sort the word list using the specified algorithm
    dictionary dict;
    if (algorithm == 1)
    {
        dict.quickSort(wordList); // Sort using quicksort
    }
    else if (algorithm == 2)
    {
        dict.heapSort(wordList); // Sort using heapsort
    }
    else
    {
        cout << "Error: invalid sorting algorithm." << endl;
        return;
    }

    // Search for words in the grid
    vector<string> wordsFound;
    for (string word : wordList)
    {
        if (dict.binarySearch(word, grid)) // Use binary search to find the word in the grid
        {
            wordsFound.push_back(word); // Add found word to the list
        }
    }

    // Print out the words found
    printWordsFound(wordsFound);
}

// Function to print out the words found
void printWordsFound(vector<string>& wordsFound)
{
    if (wordsFound.empty())
    {
        cout << "No words found." << endl;
    }
    else
    {
        cout << "Words found:" << endl;
        for (string word : wordsFound)
        {
            cout << word << endl;
        }
    }
}
