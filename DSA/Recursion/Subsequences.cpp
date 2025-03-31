#include <bits/stdc++.h>
using namespace std;

void subsequences(vector<int> input, vector<int> output, vector<vector<int>> &res, int i)
{
    if (i >= input.size())
    {
        res.push_back(output);
        return;
    }

    output.push_back(input[i]);
    subsequences(input, output, res, i + 1);
    output.pop_back();
    subsequences(input, output, res, i + 1);
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<int> output;
    vector<vector<int>> res;
    subsequences(input, output, res, 0);
    for (auto x : res)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i];
            if (i < x.size() - 1)
                cout << ','; // Add a comma if it's not the last element
        }
        cout << endl;
    }

    return 0;
}