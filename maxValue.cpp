// Copyright (c) 2025 Reid MacLean All rights reserved.
//
// Created by: Reid MacLean
// Created on: May 2025
// This program find the maximum value in a list of
// random numbers between 1 and 100 using len and max functions

#include <array>
#include <cstdlib>  // for rand_r()
#include <ctime>    // for time()
#include <iostream>

const int MAX_ARRAY_SIZE = 10;
const int MIN_NUM = 0;
const int MAX_NUM = 100;

int findMaxValue(const std::array<int, MAX_ARRAY_SIZE>& arr) {
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    std::array<int, MAX_ARRAY_SIZE> arrayOfInt;

    // Initialize seed for rand_r()
    unsigned int seed = static_cast<unsigned int>(time(NULL));

    std::cout << "Generated numbers: ";
    for (size_t i = 0; i < arrayOfInt.size(); ++i) {
        arrayOfInt[i] = (rand_r(&seed) % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
        std::cout << arrayOfInt[i] << " ";
    }
    std::cout << std::endl;

    int maxValue = findMaxValue(arrayOfInt);
    std::cout << "Maximum value: " << maxValue << std::endl;

    return 0;
}
