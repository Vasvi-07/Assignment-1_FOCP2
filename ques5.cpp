#include <iostream>
using namespace std;

void rotateMatrix90DegreesClockwise(int matrix[][3], int n) {
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - layer - 1;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i]; 

            matrix[first][i] = matrix[last - offset][first];

            matrix[last - offset][first] = matrix[last][last - offset];

            matrix[last][last - offset] = matrix[i][last];

            matrix[i][last] = top; 
        }
    }
}

void printMatrix(int matrix[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3; 
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, n);

    rotateMatrix90DegreesClockwise(matrix, n);

    cout << "\nMatrix after 90 degrees clockwise rotation:" << endl;
    printMatrix(matrix, n);

    return 0;
}