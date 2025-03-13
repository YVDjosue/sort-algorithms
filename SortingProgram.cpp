// SortingProgram.cpp
#include "SortingProgram.h"
#include "BubbleSort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

SortingProgram::SortingProgram() {
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
    std::cout << "4. Exit\n";
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
            case 3: sortNumbers(); break;
            case 4: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);
}
