#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> bruteForce(vector<vector<int>> arr, int n)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        // skip all merged intervals
        if (!ans.empty() && end <= ans.back()[1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
            else
                break;
        }
        ans.push_back({start, end});
    }
    return ans;
}
vector<vector<int>> optimal(vector<vector<int>> arr, int n)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {

        if (ans.empty()|| arr[i][0]> ans.back()[1])
            ans.push_back(arr[i]);
        else
            ans.back()[1] = max(arr[i][1], ans.back()[1]);


    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {2, 6}, {8, 10}, {15, 18},{16, 17}};
    int n = arr.size();
    // vector<vector<int>> ans = bruteForce(arr, n);
    vector<vector<int>> ans = optimal(arr, n);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
