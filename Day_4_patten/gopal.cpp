#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Input the size of the pattern
    int width = 2 * n; // Width of the pattern

    // Upper part of "G"
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == n - 1) { // Top and bottom horizontal line
                if (j < n) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            } else if (j == 0) { // Vertical line on the left
                cout << "*";
            } else if (i >= n / 2 && j == n - 1) { // Middle horizontal line to the right
                cout << "*";
            } else if (i >= n / 2 && j == n) { // Corner of "G"
                cout << "*";
            } else if (i == n / 2 && j >= n / 2) { // Middle horizontal line
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
