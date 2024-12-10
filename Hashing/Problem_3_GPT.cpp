#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Validate input for a non-negative array size
    if (n <= 0) {
        cout << "Invalid array size. Exiting program." << endl;
        return 1;  // Exit with an error code
    }

    int arr[100]; // Assuming a maximum array size of 100, adjust as needed

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    sort(arr, arr + n); // Sort the array to simplify frequency counting

    int maxElement = arr[n - 1];
    int minElement = arr[0];
    
    int freqArray[100] = {0}; // Assuming a maximum element value of 100, adjust as needed

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        freqArray[arr[i]]++;
    }

    int highestFrequency = 0, lowestFrequency = INT_MAX;
    int highestFrequencyElement, lowestFrequencyElement;

    // Find the highest and lowest frequency elements
    for (int i = 0; i <= maxElement; i++) {
        if (freqArray[i] > 0) {
            if (freqArray[i] > highestFrequency) {
                highestFrequency = freqArray[i];
                highestFrequencyElement = i;
            }

            if (freqArray[i] < lowestFrequency) {
                lowestFrequency = freqArray[i];
                lowestFrequencyElement = i;
            }
        }
    }

    cout << "Highest frequency element: " << highestFrequencyElement << " (Frequency: " << highestFrequency << ")" << endl;
    cout << "Lowest frequency element: " << lowestFrequencyElement << " (Frequency: " << lowestFrequency << ")" << endl;

    return 0;
}
