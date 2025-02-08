#include <iostream>
#include <climits>
using namespace std;

// Function to reverse the array 
void reverseMyArray(int myArr[], int totalSize) {
    int startPoint = 0;
    int endPoint = totalSize - 1;
    while (startPoint < endPoint) {
        int swapTemp = myArr[startPoint];
        myArr[startPoint] = myArr[endPoint];
        myArr[endPoint] = swapTemp;
        
        startPoint++;
        endPoint--;
    }
}

void showArray(int myArr[], int totalSize) {
    for (int i = 0; i < totalSize; i++) {
        cout << myArr[i];
        if (i < totalSize - 1) {
            cout << ", "; 
        }
    }
    cout << endl;
}

void findBiggestAndSmallest(int myArr[], int totalSize) {
    if (totalSize < 2) {
        cout << "Array needs at least 2 numbers" << endl;
        return;
    }
    
    int biggest = myArr[0], smallest = myArr[0];
    int secondBiggest = INT_MIN, secondSmallest = INT_MAX;

    for (int i = 1; i < totalSize; i++) {
        if (myArr[i] > biggest) {
            secondBiggest = biggest;
            biggest = myArr[i];
        } else if (myArr[i] > secondBiggest && myArr[i] != biggest) {
            secondBiggest = myArr[i];
        }
        
        if (myArr[i] < smallest) {
            secondSmallest = smallest;
            smallest = myArr[i];
        } else if (myArr[i] < secondSmallest && myArr[i] != smallest) {
            secondSmallest = myArr[i];
        }
    }

    if (secondBiggest == INT_MIN) {
        cout << "Second Biggest element does not exist." << endl;
    } else {
        cout << "Second Biggest element is: " << secondBiggest << endl;
    }

    if (secondSmallest == INT_MAX) {
        cout << "Second Smallest element does not exist." << endl;
    } else {
        cout << "Second Smallest element is: " << secondSmallest << endl;
    }
}

int main() {
    int arraySize;

    cout << "Enter the size of the array: ";
    cin >> arraySize;

    if (arraySize <= 0) {
        cout << "Please enter a valid size (greater than 0)" << endl;
        return 1; 
    }

    int* myArray = new int[arraySize];

    cout << "Enter " << arraySize << " numbers:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> myArray[i];
    }

    cout << "\nOriginal Array: ";
    showArray(myArray, arraySize);

    reverseMyArray(myArray, arraySize);
    cout << "Reversed Array: ";
    showArray(myArray, arraySize);

    findBiggestAndSmallest(myArray, arraySize);

    delete[] myArray;

    return 0;
}