#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm {
private:
    void merge(std::vector<int>& data, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = data[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = data[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                data[k] = L[i];
                i++;
            } else {
                data[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            data[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            data[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSortHelper(std::vector<int>& data, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortHelper(data, left, mid);
            mergeSortHelper(data, mid + 1, right);
            merge(data, left, mid, right);
        }
    }

public:
    void sort(std::vector<int>& data) override {
        mergeSortHelper(data, 0, data.size() - 1);
    }

    std::string getName() const override {
        return "Merge Sort";
    }

    std::string getComplexity() const override {
        return "O(n log n)";
    }
};

#endif // MERGESORT_H