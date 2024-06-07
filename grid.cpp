#include "Code.h"

Grid::Grid(int n) : grid(n, n), size(n) {}

void Grid::loadFromFile(const string& file) {
    ifstream inFile(file);
    if (!inFile) {
        throw fileOpenError(file);
    }
    char ch;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> ch;
            grid[i][j] = ch;
        }
    }
    inFile.close();
}

char Grid::getLetter(int i, int j) const {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        throw indexRangeError("Grid: invalid index", i, size);
    }
    return grid[i][j];
}

int Grid::getSize() const {
    return size;
}
