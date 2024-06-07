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

template <typename T>
class heap {
private:
    std::vector<T> items;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void maxHeapify(int i, int heapSize) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heapSize && items[l] > items[largest]) {
            largest = l;
        }

        if (r < heapSize && items[r] > items[largest]) {
            largest = r;
        }

        if (largest != i) {
            std::swap(items[i], items[largest]);
            maxHeapify(largest, heapSize);
        }
    }

    void buildMaxHeap() {
        int heapSize = items.size();
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            maxHeapify(i, heapSize);
        }
    }

public:
    void initializeMaxHeap() {
        buildMaxHeap();
    }

    void heapsort() {
        int heapSize = items.size();
        buildMaxHeap();
        for (int i = heapSize - 1; i > 0; i--) {
            std::swap(items[0], items[i]);
            heapSize--;
            maxHeapify(0, heapSize);
        }
    }

    T getItem(int n) {
        return items[n];
    }

    void insert(T value) {
        items.push_back(value);
    }

    int size() {
        return items.size();
    }

    T extractMax() {
        T maxItem = items[0];
        std::swap(items[0], items.back());
        items.pop_back();
        if (!items.empty()) {
            maxHeapify(0, items.size());
        }
        return maxItem;
    }
};

#endif	// HEAP_CLASS
