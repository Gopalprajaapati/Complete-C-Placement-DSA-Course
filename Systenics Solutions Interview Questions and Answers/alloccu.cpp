

#include <iostream>
#include <vector>

using namespace std;

int findOccurrences(int arr[], int size, int target) {
   
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            cout << "Found " << target << " at index " << i << endl;
           
        }
    }

  
}

int main() {
    int arr[] = {1, 3, 7, 8, 7, 5, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = findOccurrences(arr, size, target);
   if (index != -1) {
       cout << "Number " << target << " found at index " << index <<endl;
    } else {
       cout << "Number " << target << " not found in the array." <<endl;
    } 

    return 0;
}
