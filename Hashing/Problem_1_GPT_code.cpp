#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Validate input for a non-negative array size
    if (n < 0) {
        cout << "Invalid array size. Exiting program." << endl;
        return 1;  // Exit with an error code
    }

    int *arr = new int[n]; // Dynamically allocate memory for the array

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Pre-compute occurrences
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    // Validate input for a non-negative number of queries
    if (q < 0) {
        cout << "Invalid number of queries. Exiting program." << endl;
        delete[] arr; // Deallocate memory before exiting
        return 1;     // Exit with an error code
    }

    while (q--) {
        int number;
        cout << "Enter the number to fetch its occurrences: ";
        cin >> number;

        // Validate input for a valid array index
        if (number < 0 || number >= 13) {
            cout << "Invalid number. It should be between 0 and 12 (inclusive)." << endl;
            continue; // Skip the current iteration and prompt for input again
        }

        cout << "Occurrences of " << number << ": " << hash[number] << endl;
    }

    // Deallocate dynamically allocated memory
    delete[] arr;

    return 0;
}
