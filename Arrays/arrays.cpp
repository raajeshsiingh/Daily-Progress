#include <iostream>
#include <set>
#include <unordered_map>
#include<vector>
using namespace std;

// Function to generate a random array of positive integers
int* generateRandomArray(int size) {
    int* arr = new int[size];
    std::srand(std::time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100 + 1;
    }

    // Optional: Print the array for debugging
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return arr;
}

// Linear search for an element in an array
bool linearSearchFor(int element, int inArr[], int ofSize) {
    for (int i = 0; i < ofSize; i++) {
        if (inArr[i] == element) {
            return true;
        }
    }
    return false;
}

// Reverse the array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Swap adjacent elements in the array
void swapArray(int arr[], int size) {
    for (int i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

// Find the first unique element in the array
int uniqueElementIn(int arr[], int size) {
    unordered_map<int, int> frequency;

    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        if (frequency[arr[i]] == 1) {
            return arr[i];
        }
    }

    return -1; // No unique element found
}

// Check if the occurrences of elements are unique
bool uniqueOccOfElementsIn(int arr[], int size) {
    unordered_map<int, int> frequency;
    set<int> uniqueCounts;

    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    for (const auto& pair : frequency) {
        if (!uniqueCounts.insert(pair.second).second) {
            return false; // Duplicate occurrence count found
        }
    }

    return true; // All occurrence counts are unique
}

int duplicateNumberIn(int arr[], int size) {
    unordered_map<int, int> frequency;

    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            return pair.first; // Duplicate number
        }
    }
    return -1;
}

 void findAllDuplicatesIn(int arr[], int size) {
    unordered_map<int, int> frequency;
    vector<int> resultArr;

    // Count frequencies of each element
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    // Add duplicates to resultArr
    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            resultArr.push_back(pair.first); // Add duplicate element
        }
    }

    // Print resultArr
    for (int i = 0; i < resultArr.size(); i++) {
        cout << resultArr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;

    int* arr = generateRandomArray(n);

    int min = arr[0];
    int max = arr[0];

    // Find the largest and smallest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "Max is " << max << " & Min is " << min << endl;

    int element;
    cout << "Enter the element to be searched: ";
    cin >> element;

    bool linearSearchResult = linearSearchFor(element, arr, n);
    cout << "Key " << element << " is " << (linearSearchResult ? "present" : "absent") << endl;

    reverseArray(arr, n);
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    swapArray(arr, n);
    cout << "Swapped Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int dummyArr[6] = {10, 11, 12, 12};
    int uniqueNumber = uniqueElementIn(dummyArr, 4);
    cout << "Unique Element: " << (uniqueNumber == -1 ? "None" : to_string(uniqueNumber)) << endl;

    bool isUniqueOccurrence = uniqueOccOfElementsIn(dummyArr, 4);
    cout << "Unique Occurrence: " << (isUniqueOccurrence ? "True" : "False") << endl;

    // int duplicateNumber = duplicateNumberIn(dummyArr, 4);
    // cout << "Duplicate number: " << duplicateNumber << endl;

    findAllDuplicatesIn(dummyArr, 4);

    cout << endl;

    delete[] arr; // Free dynamically allocated memory
    return 0;
}
