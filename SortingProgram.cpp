#include "SortingProgram.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h" // Include new headers
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

SortingProgram::SortingProgram() {
    // Default to BubbleSort
    sorter = std::make_unique<BubbleSort>();
}

void SortingProgram::generateRandomNumbers() {
    numbers.clear();
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 1000; ++i) {
        numbers.push_back(rand() % 10000);
    }
    std::cout << "Generated 1000 random numbers.\n";
}

void SortingProgram::showNumbers() const {
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void SortingProgram::sortNumbers() {
    sorter->measureSortingTime(numbers);
}

void SortingProgram::showMenu() const {
    std::cout << "\nSorting Program Menu:\n";
    std::cout << "1. Generate Random Numbers\n";
    std::cout << "2. Show Numbers\n";
    std::cout << "3. Sort Using Bubble Sort\n";
    std::cout << "4. Sort Using Selection Sort\n";
    std::cout << "5. Sort Using Insertion Sort\n"; // New option
    std::cout << "6. Sort Using Merge Sort\n";    // New option
    std::cout << "7. Sort Using Quick Sort\n";    // New option
    std::cout << "8. Sort Using Heap Sort\n";     // New option
    std::cout << "9. Exit\n";
}

void SortingProgram::run() {
    int choice;
    do {
        showMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: generateRandomNumbers(); break;
            case 2: showNumbers(); break;
            case 3: sorter = std::make_unique<BubbleSort>(); sortNumbers(); break;
            case 4: sorter = std::make_unique<SelectionSort>(); sortNumbers(); break;
            case 5: sorter = std::make_unique<InsertionSort>(); sortNumbers(); break; // New case
            case 6: sorter = std::make_unique<MergeSort>(); sortNumbers(); break;     // New case
            case 7: sorter = std::make_unique<QuickSort>(); sortNumbers(); break;     // New case
            case 8: sorter = std::make_unique<HeapSort>(); sortNumbers(); break;      // New case
            case 9: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 9);
}