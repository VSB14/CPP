#include <bits/stdc++.h>
using namespace std;

vector<int> findPotentialDigits(const map<int, string>& digitPatterns, const string& segment) {
    vector<int> potentialDigits;

    for (const auto& [digit, pattern] : digitPatterns) {
        int mismatchCount = 0;

        for (size_t i = 0; i < segment.size(); ++i) {
            if (segment[i] != pattern[i]) {
                ++mismatchCount;
            }
        }

        if (mismatchCount <= 1) {
            potentialDigits.push_back(digit);
        }
    }

    return potentialDigits;
}

vector<vector<int>> generateCombinations(const vector<vector<int>>& allPossibleDigits) {
    vector<vector<int>> result;

    function<void(int, vector<int>&)> helper = [&](int index, vector<int>& currentCombination) {
        if (index == allPossibleDigits.size()) {
            result.push_back(currentCombination);
            return;
        }

        for (int digit : allPossibleDigits[index]) {
            currentCombination.push_back(digit);
            helper(index + 1, currentCombination);
            currentCombination.pop_back();
        }
    };

    vector<int> currentCombination;
    helper(0, currentCombination);
    return result;
}

void solve() {
    int rows = 3;
    vector<string> digitSegments(rows);
    for (int i = 0; i < rows; ++i) {
        getline(cin, digitSegments[i]);
    }

    vector<string> inputSegments(rows);
    for (int i = 0; i < rows; ++i) {
        getline(cin, inputSegments[i]);
    }

    map<int, string> digitPatterns;
    for (int digit = 0; digit < 10; ++digit) {
        stringstream patternBuilder;
        for (int row = 0; row < rows; ++row) {
            patternBuilder << digitSegments[row].substr(digit * 3, 3);
        }
        digitPatterns[digit] = patternBuilder.str();
    }

    vector<vector<int>> possibleNumbers;
    size_t digitCount = inputSegments[0].size() / 3;

    for (size_t i = 0; i < digitCount; ++i) {
        stringstream segmentBuilder;
        for (int row = 0; row < rows; ++row) {
            segmentBuilder << inputSegments[row].substr(i * 3, 3);
        }

        vector<int> matchingDigits = findPotentialDigits(digitPatterns, segmentBuilder.str());
        if (matchingDigits.empty()) {
            cout << "Invalid";
            return;
        }

        possibleNumbers.push_back(matchingDigits);
    }

    int totalSum = 0;
    for (const auto& combination : generateCombinations(possibleNumbers)) {
        stringstream numberBuilder;
        for (int digit : combination) {
            numberBuilder << digit;
        }
        totalSum += stoi(numberBuilder.str());
    }

    cout << totalSum;
}

int main() {
    solve();
    return 0;
}
