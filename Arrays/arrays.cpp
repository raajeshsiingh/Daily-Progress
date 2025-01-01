#include<iostream>
using namespace std;

// Function to generate a random array of positive integers
int* generateRandomArray(int size) {
    int* arr = new int[size]; // Dynamically allocate the array

    // Seed the random number generator
    std::srand(std::time(0));

    // Generate positive random integers between 1 and 100
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100 + 1; // Random numbers between 1 and 100
    }

    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    
    return arr; // Return the pointer to the array
}

bool linearSearchFor(int element, int inArr[], int ofSize) {
    bool isElementPresent = false;

    for (int i=0; i<ofSize; i++) {
        if (inArr[i] == element) {
            isElementPresent = true;
            break;
        }
    }
    return isElementPresent;
}

void reverseArray(int arr[], int size) {
    for (int i=0; i<size/2; i++) { 
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

int main() {
    //randomly create a array and print the largest & smallest element
    int n;
    cout << "Enter the size of Array :- ";
    cin >> n;
    int* arr = generateRandomArray(n);

    cout << endl;

    int min = arr[0];
    int max = arr[0];

    for (int i=0; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
         if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "max is " << max << " & " << "min is " << min << endl;

    int element;

    cout << "Enter the element to be searched :- ";
    cin >> element;

    bool linearSearchResult = linearSearchFor(element, arr, n);
    cout << "Key " << element << " is " << (linearSearchResult ? "present" : "absent") << endl;

    reverseArray(arr, n);

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

}