#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortAlgorithm.h"

class QuickSort : public SortAlgorithm {
private:
    int partition(std::vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }

    void quickSortHelper(std::vector<int>& data, int low, int high) {
        if (low < high) {
            int pi = partition(data, low, high);
            quickSortHelper(data, low, pi - 1);
            quickSortHelper(data, pi + 1, high);
        }
    }

public:
    void sort(std::vector<int>& data) override {
        quickSortHelper(data, 0, data.size() - 1);
    }

    std::string getName() const override {
        return "Quick Sort";
    }

    std::string getComplexity() const override {
        return "O(n log n)";
    }
};

#endif // QUICKSORT_H