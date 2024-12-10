#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    // Comparator function to sort items by value-to-weight ratio in decreasing order
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2; // Sort in decreasing order of value/weight ratio
    }

    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int W) {
        int n = values.size();
        vector<Item> arr(n);
        double totalVal = 0.0;
        int currWeight = 0;

        // Populate the array of items
        for (int i = 0; i < n; i++) {
            arr[i] = {values[i], weights[i]};
        }

        // Sort the items based on the value-to-weight ratio
        sort(arr.begin(), arr.end(), cmp);

        // Calculate the maximum total value in the knapsack
        for (int i = 0; i < n; i++) {
            if (currWeight + arr[i].weight <= W) {
                // Take the whole item
                currWeight += arr[i].weight;
                totalVal += arr[i].value;
            } else {
                // Take a fraction of the item
                int remain = W - currWeight;
                totalVal += (double)arr[i].value / arr[i].weight * (double)remain;
                break;
            }
        }

        return totalVal;
    }
};

int main() {
    Solution sol;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;

    double result = sol.fractionalKnapsack(values, weights, W);
    cout << "Maximum total value in the knapsack: " << result << endl;

    return 0;
}

//My Mistakes
// The primary parts of your code that made it incorrect for test cases were:

// 1. **Accessing Incorrect Array Properties in the Loop**:
//    - In the loop where you calculated `totalVal`, you were using `values[i]` and `weights[i]` instead of accessing the properties of `arr[i]` (i.e., `arr[i].value` and `arr[i].weight`). This led to logical errors, as `values[i]` and `weights[i]` didn't represent the sorted values after the `sort` operation.

// 2. **Struct Field Names**:
//    - Your `struct item` had fields named `values` and `weights`, which conflicted with the vectors `values` and `weights` passed as parameters. The correct field names should be `value` and `weight` to clearly distinguish between the struct properties and the input vectors.

// **Impact**:
// - Sorting used the comparator `cmp` correctly, but during the loop, accessing the original `values[i]` and `weights[i]` instead of `arr[i].value` and `arr[i].weight` meant that the program didn't use the sorted order for calculations. This mismatch led to incorrect results for test cases where sorting was crucial to find the optimal solution.