#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "SortAlgorithm.h"

class InsertionSort : public SortAlgorithm {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 1; i < data.size(); ++i) {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    std::string getName() const override {
        return "Insertion Sort";
    }

    std::string getComplexity() const override {
        return "O(n^2)";
    }
};

#endif // INSERTIONSORT_H