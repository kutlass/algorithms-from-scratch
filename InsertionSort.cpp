#include <iostream>

void InsertionSort(int numbers[], int numbersSize) {
    for (int i = 1; i < numbersSize; i++) {
        int j = i;

        while (j > 0 && numbers[j - 1] > numbers[j] ) {
            // if element to my left is bigger
            // than me, then swap our values
            int leftElementPreSwap = numbers[j - 1];
            numbers[j - 1] = numbers[j];         // Assign left element's new post-swap value
            numbers[j]     = leftElementPreSwap; // Assign current element's new post-swap value

            --j;
        }
    }
}

int main() {
    int numbers[] = {13, 2, 17, 10, 4};
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before InsertionSort():" << std::endl;
    for (int i = 0; i < numbersSize; i++) {
    std::cout << numbers[i] << std::endl;
    }

    InsertionSort(numbers, numbersSize);

    std::cout << "After InsertionSort():" << std::endl;
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << std::endl;
    }
  
    return 0;
}
