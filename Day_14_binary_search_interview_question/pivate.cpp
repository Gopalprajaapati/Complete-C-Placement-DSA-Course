#include <iostream>
using namespace std;

// Function to find the index of the smallest element in a rotated sorted array
int getprivate(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int mid;
    
    // Handle cases where the array is not rotated
    if (arr[start] <= arr[end]) {
        return 0;
    }
    
    while (start < end) {
        mid = start + (end - start) / 2;
        
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

// Standard binary search function
int binary_search(int arr[], int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
       
        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }      
    }
    return -1;
}

int main() {
    int arr[] = {3, 8, 10, 17, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;  // Example key to search

    int privat = getprivate(arr, size);
    cout << "Index of the smallest element: " << privat << endl;
    cout << "Smallest element: " << arr[privat] << endl;

    int result = -1;
    
    // Determine which part of the array to perform binary search on
    if (key >= arr[privat] && key <= arr[size - 1]) {
        // Search in the right part
        result = binary_search(arr, privat, size - 1, key);
    } else {
        // Search in the left part
        result = binary_search(arr, 0, privat - 1, key);
    }

    if (result != -1) {
        cout << "Element " << key << " found at index: " << result << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
