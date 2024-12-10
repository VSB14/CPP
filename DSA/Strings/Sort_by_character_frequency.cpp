#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

string fetchSorted(unordered_map<char, int> count) {
    map<int, vector<char>> FreqChar;

    // Group characters by frequency
    for (auto it : count) {
        FreqChar[it.second].push_back(it.first);
    }

    string result;

    // Iterate from highest to lowest frequency
    for (auto it = FreqChar.rbegin(); it != FreqChar.rend(); ++it) {
        for (char ch : it->second) {
            result.append(it->first, ch);  // Append each character `it->first` times
        }
    }

    return result;
}

int main() {
    string s = "tree";
    unordered_map<char, int> count;

    // Count character frequencies
    for (char ch : s) {
        count[ch]++;
    }

    // Fetch sorted result by frequency
    string result = fetchSorted(count);
    cout << result << endl;

    return 0;
}
