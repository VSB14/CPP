#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;

vector<int> findPSEE(vector<int> &nums, int n)
{
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

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

int findLargestHist(vector<int> &vect, int n)
{
    vector<int> res;
    int ans;
    vector<int> nse;
    vector<int> psee;
    stack<int> st;
    nse = findNSE(vect, n);
    psee = findPSEE(vect, n);
    for (int i = 0; i < vect.size(); i++)
    {
        int x = vect[i]*(nse[i]-psee[i]-1);
        res.push_back(x);
    }
    ans = *max_element(res.begin(), res.end());
    return ans;
}

int main()
{
    vector<int> vect = {9,0};
    int n = vect.size();
    int res;
    res = findLargestHist(vect, n);
    cout << "Result: " << res;
    return 0;
}