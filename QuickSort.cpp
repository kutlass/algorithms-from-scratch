#include <iostream>
#include <chrono>

int Partition(int numbers[], int lowIndex, int highIndex) {
    // Pick middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = numbers[midpoint];

    bool done = false;
    while (!done) {
        // Increment lowIndex while numbers[lowIndex] < pivot
        while (numbers[lowIndex] < pivot) {
            lowIndex += 1;
        }

        // Decrement highIndex while pivot < numbers[highIndex]
        while (pivot < numbers[highIndex]) {
            highIndex -= 1;
        }

        // If zero or one elements remain, then all numbers are
        // partitioned. Return highIndex.
        if (lowIndex >= highIndex) {
            done = true;
        }
        else {
            // Swap numbers[lowIndex] and numbers[highIndex]
            int temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            // Update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }

    return highIndex;
 }

void Quicksort(int numbers[], int lowIndex, int highIndex) {
    // Base case: If the partition size is 1 or zero
    // elements, then the partition is already sorted
    if (lowIndex >= highIndex) {
        return;
    }

    // Partition the data within the array. Value lowEndIndex
    // returned from partitioning is the index of the low
    // partition's last element.
    int lowEndIndex = Partition(numbers, lowIndex, highIndex);

    // Recursively sort low partition (lowIndex to lowEndIndex)
    // and high partition (lowEndIndex + 1 to highIndex)
    Quicksort(numbers, lowIndex, lowEndIndex);
    Quicksort(numbers, lowEndIndex + 1, highIndex);
 }

int main() {
    int numbers[] = {
        2, 8, 5, 3, 9, 4, 1
    };

    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before Quicksort():\n";
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << std::endl;
    }

    auto start = std::chrono::high_resolution_clock::now();

    Quicksort(numbers, 0, numbersSize - 1);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);

    std::cout << "\nAfter Quicksort():\n";
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << std::endl;
    }

    std::cout << "\nQuicksort() took " << duration.count() << " ms\n";

    return 0;
}
