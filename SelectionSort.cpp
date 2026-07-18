#include <iostream>
#include <chrono>

void SelectionSort(int numbers[], int numbersSize) {
    for (int i = 0; i < numbersSize - 1; ++i) {
        // Record the position of the smallest
        // value found so we know where to swap
        int indexSmallest = i; // Assume position i holds the smallest value
                               // until we know more from the j scan below
        for (int j = i + 1; j < numbersSize; ++j) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }

        // Perform the swap
        int currentElementPreSwap = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = currentElementPreSwap;
    }
}

int main() {
    int numbers[] = {
        2, 8, 5, 3, 9, 4, 1
        };

    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before SelectionSort():\n";
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << std::endl;
    }

    auto start = std::chrono::high_resolution_clock::now();

    SelectionSort(numbers, numbersSize);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    std::cout << "\nAfter SelectionSort():\n";
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << std::endl;
    }

    std::cout << "\nInsertionSort took " << duration.count() << " ms\n";

    return 0;
}
