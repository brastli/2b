// Name: Sofia Kolobaev, Page Patterson, Minghao Zhu
// Group ID: kolpatzhu
// Group Number: 6
// Problem Set: Project 2
// Header file Code.h. Contains class definitions for dictionary, grid, and the
// global functions findMatches and search

#ifndef HEAP_CLASS
#define HEAP_CLASS

#include <vector>
#include <algorithm>

// Template class for a max-heap
template <typename T>
class heap {
private:
    std::vector<T> items; // Vector to store heap items

    // Helper functions to get the parent, left, and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Function to maintain the max-heap property starting from index i
    void maxHeapify(int i, int heapSize) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        // Find the largest among the current node and its children
        if (l < heapSize && items[l] > items[largest]) {
            largest = l;
        }

        if (r < heapSize && items[r] > items[largest]) {
            largest = r;
        }

        // Swap and continue heapifying if the current node is not the largest
        if (largest != i) {
            std::swap(items[i], items[largest]);
            maxHeapify(largest, heapSize);
        }
    }

    // Function to build a max-heap from an unordered array
    void buildMaxHeap() {
        int heapSize = items.size();
        // Start from the last non-leaf node and heapify each node
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            maxHeapify(i, heapSize);
        }
    }

public:
    // Public function to initialize the max-heap
    void initializeMaxHeap() {
        buildMaxHeap();
    }

    // Public function to sort the heap using heapsort algorithm
    void heapsort() {
        int heapSize = items.size();
        buildMaxHeap();
        // Swap the root of the heap with the last item and reduce the heap size
        for (int i = heapSize - 1; i > 0; i--) {
            std::swap(items[0], items[i]);
            heapSize--;
            maxHeapify(0, heapSize); // Heapify the reduced heap
        }
    }

    // Function to get the item at index n
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

    // Function to extract the maximum value (root) from the heap
    T extractMax() {
        T maxItem = items[0]; // The root of the heap is the max item
        std::swap(items[0], items.back()); // Swap the root with the last item
        items.pop_back(); // Remove the last item (previously the root)
        if (!items.empty()) {
            maxHeapify(0, items.size()); // Heapify the reduced heap
        }
        return maxItem; // Return the maximum item
    }
};

#endif	// HEAP_CLASS
