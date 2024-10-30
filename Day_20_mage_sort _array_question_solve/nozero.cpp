#include <iostream>
#include <algorithm> // For std::swap

void rearrangeArray(int arr[], int n) {
    int nonZeroIndex = 0; // Position to place the next non-zero element

    // Move all non-zero elements to the beginning of the array
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            std::swap(arr[i], arr[nonZeroIndex]);
            nonZeroIndex++;
        }
    }

    // Sort only the non-zero part of the array
    // std::sort(arr, arr + nonZeroIndex);

    // Remaining elements from nonZeroIndex to the end are already zeros
}

int main() {
    int arr1[] = {2, 0, 1, 0, 3, 0};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    rearrangeArray(arr1, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr1[i] << " ";
    }

    return 0;
}
