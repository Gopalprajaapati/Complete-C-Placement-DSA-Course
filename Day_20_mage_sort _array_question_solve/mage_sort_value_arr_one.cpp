#include <iostream>
using namespace std;

void merge_in_place(int arr1[], int size1, int arr2[], int size2, int finalSize) {
    int i = size1 - 1; // Last index of the initial part of arr1
    int j = size2 - 1; // Last index of arr2
    int k = finalSize - 1; // Last index of the final merged array

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    // Copy remaining elements of arr2, if any
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

void array_print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 0, 0, 0}; 
    int arr2[] = {2, 5, 6}; 
    int size1 = 3; // Number of initial elements in arr1
    int size2 = 3; // Number of elements in arr2
    int finalSize = size1 + size2; // Total number of elements after merge

    merge_in_place(arr1, size1, arr2, size2, finalSize);
    array_print(arr1, finalSize);

    return 0;
}
