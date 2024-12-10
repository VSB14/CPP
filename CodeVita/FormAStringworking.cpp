#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int calculateMinCost(int numSubstrings, vector<pair<string, int>> &stringCosts, string targetString) {
    int targetLength = targetString.length();
    vector<int> dp(targetLength + 1, INT_MAX); 
    dp[0] = 0; 

    for (int i = 0; i <= targetLength; ++i) {
        if (dp[i] == INT_MAX) continue; 

        for (auto &substringData : stringCosts) {
            string currentSubstring = substringData.first;
            int currentCost = substringData.second;
            int currentSubstringLength = currentSubstring.length();      

            if (i + currentSubstringLength <= targetLength && targetString.substr(i, currentSubstringLength) == currentSubstring) {
                dp[i + currentSubstringLength] = min(dp[i + currentSubstringLength], dp[i] + currentCost); 

                for (int k = 1; k < currentSubstringLength; ++k) {
                    if (i + k <= targetLength && targetString.substr(i, k) == currentSubstring.substr(0, k)) {
                        dp[i + k] = min(dp[i + k], dp[i] + currentCost);
                    }
                }
            }      
        }
    }

    return (dp[targetLength] == INT_MAX) ? -1 : dp[targetLength]; 
}

int main() {
    int numSubstrings;
    cin >> numSubstrings;
    
    vector<pair<string, int>> stringCosts;
    for (int i = 0; i < numSubstrings; ++i) {
        string substring;
        int cost;
        cin >> substring >> cost;
        stringCosts.push_back({substring, cost});
    }

    string targetString;
    cin >> targetString;

    int result = calculateMinCost(numSubstrings, stringCosts, targetString);

    if (result == -1) {
        cout << "Impossible";
    } else {
        cout << result;
    }

    return 0;
}
