class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
            int size = nums.size();
            vector<int> res(size);
            int posIndex = 0;
            int negIndex = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0 && posIndex < nums.size())
                {
                    res[posIndex] = nums[i];
                    posIndex += 2;
                }
                else if (nums[i] < 0 && negIndex < nums.size())
                {
                    
                    res[negIndex] = nums[i];
                    negIndex += 2;
                }
            }
            return res;
        }
};