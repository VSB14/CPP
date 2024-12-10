#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)

{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return n; // If no missing number is found, return n
}

int main()
{
    vector<int> nums{1, 2, 3, 0};
    int result = missingNumber(nums);
    cout << "Missing number: " << result << endl;
    return 0;
}