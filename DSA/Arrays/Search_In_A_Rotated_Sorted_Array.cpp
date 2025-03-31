#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &input, int left, int right, int target)
{

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == input[mid])
        {
            return mid;
        }
        // left sorted portion
        if (input[left] <= input[mid])
        {
            if (target <= input[mid] || target >= input[left]) // if the target is not part of the left sorted array
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {                                                       // right sorted portion
            if (target >= input[mid] || target <= input[right]) // if the target is not part of the right sorted array
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> input = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int left = 0, right = input.size() - 1;
    int res = binary_search(input, left, right, target);
    cout << "Result " << res;
    return 0;
}