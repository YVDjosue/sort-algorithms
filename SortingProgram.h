// SortingProgram.h
#ifndef SORTINGPROGRAM_H
#define SORTINGPROGRAM_H

#include <vector>
#include <memory>
#include "SortAlgorithm.h"

class SortingProgram {
public:
    SortingProgram();
    void run();

private:
    std::vector<int> numbers;
    std::unique_ptr<SortAlgorithm> sorter;

    void generateRandomNumbers();
    void showNumbers() const;
    void sortNumbers();
    void showMenu() const;
};

#endif // SORTINGPROGRAM_H