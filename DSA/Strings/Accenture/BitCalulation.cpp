#include <iostream>
using namespace std;

string AND(string s1, string s2, int n, int n1)
{
    string ans = "";
    cout << s1[0] << endl
         << s2[0] << endl;
    int i = n1;
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] == '1' && s2[i] == '1')
            ans += "1";
        else
            ans += "0";
    }
    cout << ans << endl;
    return ans;
}
string OR(string s1, string s2, int n, int n1)
{
    string ans = "";

    int i = n1;
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] == '1' || s2[i] == '1')
            ans += "1";
        else
            ans += "0";
    }

    return ans;
}
string XOR(string s1, string s2, int n, int n1)
{
    string ans = "";
    int i = n1;
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] == '1' && s2[i] == '1')
            ans += "0";
        else
            ans += "1";
    }

    return ans;
}

int main()
{
    // given operations are AND, OR , XOR
    string s[3] = {"1101", "1011", "OR"};
    int n = sizeof(s) / sizeof(s[0]);
    int n1 = s[0].length();
    // cout<<n1;
    string res;
    string s1 = s[0];
    string s2 = s[1];
    if (s[n - 1] == "AND")
        res = AND(s1, s2, n, n1);
    else if (s[n - 1] == "OR")
        res = OR(s1, s2, n, n1);
    else if (s[n - 1] == "XOR")
        res = XOR(s1, s2, n, n1);
    cout << res;
    return 0;
}