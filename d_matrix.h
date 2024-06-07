#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include <vector>
#include <algorithm>
#include "d_except.h"

using namespace std;

template <typename T>
class matrix
{
	public:
		matrix(int numRows = 1, int numCols = 1, const T& initVal = T());
			// constructor.
			// Postcondition: create array having numRows x numCols elements
			// all of whose elements have value initVal

		vector<T>& operator[] (int i);
			// index operator.
			// Precondition: 0 <= i < nRows. a violation of this
			// precondition throws the indexRangeError exception.
			// Postcondition: if the operator is used on the left-hand
			// side of an assignment statement, an element of row i 
			// is changed

		const vector<T>& operator[](int i) const;
			// version for constant objects

      int rows() const;
			// return number of rows
      int cols() const;
			// return number of columns

      void resize(int numRows, int numCols);
			// modify the matrix size.
			// Postcondition: the matrix has size numRows x numCols.
			// any new elements are filled with the default value of type T

	private:
      int nRows, nCols;
			// number of rows and columns

      vector<vector<T> > mat;
			// matrix is implemented as nRows vectors (rows),
			// each having nCols elements (columns)
};

template <typename T>
matrix<T>::matrix(int numRows, int numCols, const T& initVal):
	nRows(numRows), nCols(numCols),
	mat(numRows, vector<T>(numCols,initVal))
{}

// non-constant version. provides general access to matrix
// elements
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{
	if (i < 0 || i >= nRows)
		throw indexRangeError(
			"matrix: invalid row index", i, nRows);

   return mat[i];
}

// constant version.  can be used with a constant object.
// does not allow modification of a matrix element
template <typename T>
const vector<T>& matrix<T>::operator[] (int i) const
{
	if (i < 0 || i >= nRows)
		throw indexRangeError(
			"matrix: invalid row index", i, nRows);

   return mat[i];
}

template <typename T>
int matrix<T>::rows() const
{
   return nRows;
}

template <typename T>
int matrix<T>::cols() const
{
   return nCols;
}

template <typename T>
void matrix<T>::resize(int numRows, int numCols)
{
   int i;
   
   // handle case of no size change with a return
   if (numRows == nRows && numCols == nCols)
      return;

	// assign the new matrix size
	nRows = numRows;
	nCols = numCols;

	// resize to nRows rows
	mat.resize(nRows);

	// resize each row to have nCols columns
	for (i=0; i < nRows; i++)
		mat[i].resize(nCols);
}

template <typename T>
class heap {
private:
    // Vector to store heap items
    std::vector<T> items;

    // Helper functions to calculate parent, left child, and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Function to maintain the max heap property at a given index
    void maxHeapify(int i, int heapSize) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        // Find the largest among root, left child, and right child
        if (l < heapSize && items[l] > items[largest]) {
            largest = l;
        }

        if (r < heapSize && items[r] > items[largest]) {
            largest = r;
        }

        // Swap and continue heapifying if root is not largest
        if (largest != i) {
            std::swap(items[i], items[largest]);
            maxHeapify(largest, heapSize);
        }
    }

    // Function to build a max heap from the items vector
    void buildMaxHeap() {
        int heapSize = items.size();

        // Perform reverse level-order traversal from last non-leaf node
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            maxHeapify(i, heapSize);
        }
    }

public:
    // Public function to initialize the max heap
    void initializeMaxHeap() {
        buildMaxHeap();
    }

    // Public function to perform heapsort on the items
    void heapsort() {
        int heapSize = items.size();

        // Build the max heap
        buildMaxHeap();

        // Extract elements from the heap one by one
        for (int i = heapSize - 1; i > 0; i--) {
            // Move current root to end
            std::swap(items[0], items[i]);
            // Reduce heap size and heapify the root
            heapSize--;
            maxHeapify(0, heapSize);
        }
    }

    // Function to get an item at a specific index
    T getItem(int n) {
        return items[n];
    }

    // Function to insert a new value into the heap
    void insert(T value) {
        items.push_back(value);
    }

    // Function to get the current size of the heap
    int size() {
        return items.size();
    }
};


#endif	// MATRIX_CLASS
