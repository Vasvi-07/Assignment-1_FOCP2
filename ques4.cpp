#include <iostream>
using namespace std;

void printSpiralPattern(int n) {
    int spiral[n][n];  // Create an n x n matrix
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;
    int value = 1;  // Start filling the matrix with value 1

    // Fill the matrix in a spiral manner
    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; i++) {
            spiral[startRow][i] = value++;
        }
        startRow++;

        for (int i = startRow; i <= endRow; i++) {
            spiral[i][endCol] = value++;
        }
        endCol--;

        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                spiral[endRow][i] = value++;
            }
            endRow--;
        }

        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                spiral[i][startCol] = value++;
            }
            startCol++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiral[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the spiral matrix (n): ";
    cin >> n;

    printSpiralPattern(n);

    return 0;
}