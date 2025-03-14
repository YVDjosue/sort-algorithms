#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortAlgorithm.h"

class SelectionSort : public SortAlgorithm {
public:
    void sort(std::vector<int>& data) override {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(data[i], data[minIndex]);
            }
        }
    }

    std::string getName() const override {
        return "Selection Sort";
    }

    std::string getComplexity() const override {
        return "O(n^2)";
    }
};

#endif // SELECTIONSORT_H