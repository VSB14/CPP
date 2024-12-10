#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int mod = 1e9+7;

vector<int> findNSE(vector<int> &nums, int n)
{
    // vector<int> res(n);
    stack<int> st;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}
vector<int> findPSEE(vector<int> &nums, int n)
{
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}
vector<int> findNGE(vector<int> &nums, int n)
    {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] >= nums[st.top()])
            {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> findPGEE(vector<int> &nums, int n)
    {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
int sumMin(vector<int> &nums, int n)
{

    vector<int> NSE(n);
    vector<int> PSEE(n);
    NSE = findNSE(nums, n);
    PSEE = findPSEE(nums, n);
    long long total = 0 ;
    for (int i = 0; i < n; i++)
    {
        long long left = i - PSEE[i];
        long long right = NSE[i] - i;
        total = (total + (left * right * nums[i]) % mod) % mod;
    }
    return total;
}
int sumMax(vector<int> &nums, int n)
    {

        vector<int> NGE(n);
        vector<int> PGEE(n);
        NGE = findNGE(nums, n);
        PGEE = findPGEE(nums, n);
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            long long left = i - PGEE[i];
            long long right = NGE[i] - i;
            total = (total + (left *right *nums[i]) % mod) % mod;
        }
        return total;
    }
long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        return sumMax(nums, n) - sumMin(nums, n);
    }

int main()
{
    vector<int> nums = {4,-2,-3,4,1};
    int n = nums.size();

    vector<int> nse(n);
    vector<int> nge(n);
    vector<int> psee(n);
    vector<int> pgee(n);
    nse = findNSE(nums, n);
    // cout << "NSE below" << endl;
    // for (auto x : nse)
    // {
    //     cout << x << endl;
    // }
    psee = findPSEE(nums, n);
    // cout << "PSEE below" << endl;
    for (auto x : psee)
    {
        cout << x << endl;
    }
    int totalMin = 0;
    totalMin = sumMin(nums,n);
    cout<<"TotalMin: "<<totalMin<<endl;
    nge = findNGE(nums, n);
    // cout << "NGE below" << endl;
    // for (auto x : nge)
    // {
    //     cout << x << endl;
    // }
    
    pgee = findPGEE(nums, n);
    // cout << "PSEE below" << endl;
    // for (auto x : pgee)
    // {
    //     cout << x << endl;
    // }
    int totalMax = 0;
    totalMax = sumMax(nums,n);
    cout<<"TotalMax: "<<totalMax<<endl;
    long long res = 0;
    res = subArrayRanges(nums);
    cout<<"Result: "<<res<<endl;
    return 0;
}