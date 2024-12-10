class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int size = nums.size();
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = 1; j < size - 1; j++)
            {
                if (nums[i] + nums[j] == k)
                {
                    sum++;
                }
                res = max(res, sum);
            }
        }
        return res;
    };