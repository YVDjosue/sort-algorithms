#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "SortAlgorithm.h"

class HeapSort : public SortAlgorithm {
private:
    void heapify(std::vector<int>& data, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] > data[largest])
            largest = left;

        if (right < n && data[right] > data[largest])
            largest = right;

        if (largest != i) {
            std::swap(data[i], data[largest]);
            heapify(data, n, largest);
        }
    }

public:
    void sort(std::vector<int>& data) override {
        int n = data.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(data, n, i);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; --i) {
            std::swap(data[0], data[i]);
            heapify(data, i, 0);
        }
    }

    std::string getName() const override {
        return "Heap Sort";
    }

    std::string getComplexity() const override {
        return "O(n log n)";
    }
};

#endif // HEAPSORT_H