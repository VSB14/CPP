#include <iostream>
#include<string>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string s[2] = {"racecar", "hello"};
    int n = sizeof(s)/sizeof(s[0]);

    for (int i = 0; i < n ; i++)
    {
        bool res = false;
        res = isPalindrome(s[i]);
        cout << boolalpha << res<<endl; // using boolaplpha to print boolean true or false in output
    }

    return 0;
}