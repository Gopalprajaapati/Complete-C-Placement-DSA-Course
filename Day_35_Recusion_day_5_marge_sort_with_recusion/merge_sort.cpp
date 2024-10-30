#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int s, int mid, int e) {
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy data to temporary arrays
    for (int i = 0; i < len1; i++)
        left[i] = arr[s + i];
    for (int j = 0; j < len2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[s..e]
    int i = 0, j = 0, k = s;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left[], if any
    while (i < len1) {
        arr[k++] = left[i++];
    }

    // Copy the remaining elements of right[], if any
    while (j < len2) {
        arr[k++] = right[j++];
    }

    // Deallocate memory
    delete[] left;
    delete[] right;
}

// Function to perform merge sort
void mergeSort(int arr[], int s, int e) {
    if (s >= e) {
        return; // Base case: if the array has 1 or 0 elements, it's already sorted
    }

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);      // Sort the first half
    mergeSort(arr, mid + 1, e);  // Sort the second half
    merge(arr, s, mid, e);       // Merge the two halves
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 6, 7, 21, 98, 44};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
