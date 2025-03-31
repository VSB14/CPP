#include <bits/stdc++.h>
using namespace std;

void solve(string digit, string output, int i, vector<string> &ans, string mapping[])
{
    // base condition
    if (i >= digit.length())
    {
        ans.push_back(output);
        return;
    }
    int num = digit[i] - '0';
    string value = mapping[num];
    for (int j = 0; j < value.length(); j++)
    {
        output.push_back(value[j]);
        solve(digit, output, i + 1, ans, mapping);
        output.pop_back();
    }
}

int main()
{
    string digit = "23456";
    string output;
    int i = 0; // position of processing digit
    vector<string> ans;
    if (digit.length() == 0)
    {
        cout << "Empty string";
        return 0;
    }
    string mapping[10] = {"", "", "abc", "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digit, output, i, ans, mapping);
    cout << "Result below: " << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it;
        if (it != ans.end() - 1)
        { // Compare iterators correctly
            cout << ',';
        }
    }

    return 0;
}