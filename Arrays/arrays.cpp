#include<iostream>
using namespace std;

// Function to generate a random array of positive integers
int* generateRandomArray(int size) {
    int* arr = new int[size]; // Dynamically allocate the array

    // Seed the random number generator
    std::srand(std::time(0));

    // Generate positive random integers between 1 and 100
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Random numbers between 1 and 100
    }

    return arr; // Return the pointer to the array
}

int main() {
    //randomly create a array and print the largest element
    int n;
    cin >> n;
    int* arr = generateRandomArray(n);

    for (int i=0; i<n-1; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    int min = arr[0];
    int max = arr[0];

    for (int i=0; i<n-1; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
         if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "max is " << max << " & " << "min is " << min << endl;

}