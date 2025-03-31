#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int num, string output, int open, int close, vector<string> &ans)
{
    if (open == num && close == num)
    {
        ans.push_back(output);
        return;
    }
    if (open < num)
    {
        output.push_back('(');
        generateParenthesis(num, output, open + 1, close, ans);
        output.pop_back();
    }
    if (close < open)
    {
        output.push_back(')');
        generateParenthesis(num, output, open, close + 1, ans);
        output.pop_back();
    }
}

int main()
{
    int num = 1;
    vector<string> ans;
    string output;
    int open = 0, close = 0;
    if(num == 0){
        return 0;
    }

    generateParenthesis(num, output, open, close, ans);
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