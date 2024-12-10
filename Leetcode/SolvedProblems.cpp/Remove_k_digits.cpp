#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
string removeKdigits(string num, int k)
{
    stack<char> st;
    int n = num.length();
    vector<char> resVect;
    string res = "";
    if (k == n)
    {
        res = '0';
        return res;
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && num[i] < st.top() && k > 0)
        {
            cout << "Popped: " << st.top() << endl;
            st.pop();
            k--;
        }

        cout << "Pushed: " << num[i] << endl;
        cout << "K now: " << k << endl;

        st.push(num[i]);
    }
    // print currect stack

    while (k > 0)
    {
        st.pop();
        k--;
    }

    // if (st.empty())

    // return "0";

    while (!st.empty())
    {

        cout << "Pushed in res: " << st.top() << endl;
        res += st.top();
        cout << "Currect res: " << res << endl;
        st.pop();
    }
    reverse(res.begin(), res.end());
        cout << "Currect res: " << res << endl;
    int start = 0;

    while (start < res.size() && res[start] == '0')
    {
        start++;
    }
    res = res.substr(start); // Get the substring from the first non-zero character onwards

    return res.empty() ? "0" : res;
}

int main()
{
    string num = "10200";
    int k = 1;
    string res;
    res = removeKdigits(num, k);
    cout << "Print Result: " << res << endl;
    return 0;
}
