#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string x)
{
    string y = x;
    reverse(y.begin(), y.end());
    return x ==y; 
}

int main()
{
    string str = "ABDA";
    bool result  = isPalindrome(str);
    cout<<"Result is : "<< result;
    return 0;
}