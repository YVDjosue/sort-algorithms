// BubbleSort.h
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm {
public:
    void sort(std::vector<int>& data) override {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }

    std::string getName() const override {
        return "Bubble Sort";
    }

    std::string getComplexity() const override {
        return "O(n^2)";
    }
};

#endif // BUBBLESORT_H
