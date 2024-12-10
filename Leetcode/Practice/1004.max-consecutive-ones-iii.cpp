/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;
        int res = 0;
        vector<int> mpp;
        while (right < nums.size())
        {
            while (right >= left)
            {
                mpp[arr[0]]++;
                if (mpp[arr[0]] == k - 1)
                {
                    res = max(res, right - left + 1);
                    left max(mpp[arr[right] + 1, left])
                }
            }
        }
        return res;
    }
};
// @lc code=end
