//there is a next_permutation function in cpp stl as well
//brute force would be to find all the permutations, sort them and then find the next

class Solution
{

    public:
        void nextPermutation(vector<int> &nums)
        {
           	//find the largest prefix
           	//now you'll get the break point
           	//find the element to swap with the breakpoint
           	//reverse the rest of the elements after the breakpoint
            int ind = -1;
            int n = nums.size();
            for (int i = n - 2; i >= 0; i--)
            {
                if (nums[i]<nums[i+1])
                {
                    ind = i;
                    break;
                }
            }
            if (ind == -1)
            {
                reverse(nums.begin(), nums.end());
            }
            else
            {

                for (int i = n - 1; i > ind; i--)
                {
                    if (nums[i] > nums[ind])
                    {
                        swap(nums[ind], nums[i]);
                        break;
                    }
                }
                reverse(nums.begin() + ind + 1, nums.end());
            }
        }
};