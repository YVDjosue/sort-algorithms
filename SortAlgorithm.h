// SortAlgorithm.h
#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

class SortAlgorithm {
public:
    virtual ~SortAlgorithm() = default;
    virtual void sort(std::vector<int>& data) = 0;
    virtual std::string getName() const = 0;
    virtual std::string getComplexity() const = 0;

    void measureSortingTime(std::vector<int>& data) {
        auto start = std::chrono::high_resolution_clock::now();
        sort(data);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Sorting Method: " << getName() << "\n";
        std::cout << "Time taken: " << elapsed.count() << " ms\n";
        std::cout << "Complexity: " << getComplexity() << "\n";
    }
};

#endif // SORTALGORITHM_H