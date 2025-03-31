#include <bits/stdc++.h>
using namespace std;

int Longest_substring(string s)
{
    int maxLen = 0, left = 0, right = 0;
    unordered_map<char, int> mpp; // Map to store frequency of characters

    while (right < s.length())
    {
        mpp[s[right]]++; // Add the character at the right index to the map

        // If the size of the map exceeds `k`, shrink the window from the left
        while (mpp.size() > right - left + 1)
        {
            mpp[s[left]]--; // Decrease the frequency of the character at the left index
            if (mpp[s[left]] == 0)
                mpp.erase(s[left]); // Remove the character if its count becomes zero
            left++;                 // Move the left pointer
        }

        // If the map size equals `k`, update the maximum length
        if (mpp.size() == right - left + 1)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++; // Move the right pointer
    }

    return maxLen;
}

int main()
{
    string s = "geeksforgeeks";

    int ans = Longest_substring(s);
    cout << "Required Ans is: " << ans;
    return 0;
}
