//Prime Number Checker & Factor Giver
#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
int PrimeChecker(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to find the next prime greater than n
int NextPrime(int n) {
    int next = n + 1;
    while (true) {
        if (PrimeChecker(next)== 1 ) return next;
        ++next;
    }
}

//Finding factors if not prime
void FactorFinder(int n) {
    cout << "Factors of " << n << ": ";
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << n << endl;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (PrimeChecker(n)) {
        cout << n << " is a prime number." << endl;
        cout << "The next prime number is " << NextPrime(n) << "." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
        FactorFinder(n);
    }

    return 0;
}