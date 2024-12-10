#include <bits/stdc++.h>
using namespace std;
typedef long long vsbLong;

int main() {
    int vsbNumLines;
    cin >> vsbNumLines;
    vector<vector<pair<int, int>>> vsbPaths(vsbNumLines);
    map<pair<int, int>, vector<int>> vsbPointToSegmentsMap;

    // Input paths for each line segment
    for (int vsbLineIndex = 0; vsbLineIndex < vsbNumLines; vsbLineIndex++) {
        int vsbX1, vsbY1, vsbX2, vsbY2;
        cin >> vsbX1 >> vsbY1 >> vsbX2 >> vsbY2;

        int vsbDeltaX = vsbX2 - vsbX1, vsbDeltaY = vsbY2 - vsbY1;
        int vsbStepCount = max(abs(vsbDeltaX), abs(vsbDeltaY));
        int vsbStepX = (vsbDeltaX == 0) ? 0 : vsbDeltaX / abs(vsbDeltaX);
        int vsbStepY = (vsbDeltaY == 0) ? 0 : vsbDeltaY / abs(vsbDeltaY);

        // Track all points in the segment path
        for (int vsbStep = 0; vsbStep <= vsbStepCount; vsbStep++) {
            int vsbCurrentX = vsbX1 + vsbStepX * vsbStep;
            int vsbCurrentY = vsbY1 + vsbStepY * vsbStep;
            vsbPaths[vsbLineIndex].emplace_back(make_pair(vsbCurrentX, vsbCurrentY));
            vsbPointToSegmentsMap[{vsbCurrentX, vsbCurrentY}].emplace_back(vsbLineIndex);
        }
    }

    string vsbInput;
    getline(cin, vsbInput); // Clear the buffer
    getline(cin, vsbInput); // Read the next line
    unordered_map<string, int> vsbValueMap;

    // Parsing input data into a map
    int vsbPos = 0, vsbInputLength = vsbInput.size();
    while (vsbPos < vsbInputLength) {
        size_t vsbColonPos = vsbInput.find(':', vsbPos);
        if (vsbColonPos == string::npos) break;
        string vsbKey = vsbInput.substr(vsbPos, vsbColonPos - vsbPos);
        vsbPos = vsbColonPos + 1;
        size_t vsbSpacePos = vsbInput.find(' ', vsbPos);
        if (vsbSpacePos == string::npos) vsbSpacePos = vsbInputLength;
        int vsbValue = stoi(vsbInput.substr(vsbPos, vsbSpacePos - vsbPos));
        vsbValueMap[vsbKey] = vsbValue;
        vsbPos = vsbSpacePos + 1;
    }

    string vsbTarget;
    cin >> vsbTarget;

    vsbLong vsbTotalCost = 0;

    // Calculate total overlap cost
    for (auto &vsbEntry : vsbPointToSegmentsMap) {
        if (vsbEntry.second.size() >= 2) {
            int vsbOverlapCount = vsbEntry.second.size();
            int vsbMinimumCost = INT_MAX;

            for (auto vsbSegmentID : vsbEntry.second) {
                auto &vsbSegmentPath = vsbPaths[vsbSegmentID];
                size_t vsbPathLength = vsbSegmentPath.size();
                size_t vsbIndex = find(vsbSegmentPath.begin(), vsbSegmentPath.end(), vsbEntry.first) - vsbSegmentPath.begin();
                int vsbLeftMoves = vsbIndex;
                int vsbRightMoves = vsbPathLength - vsbIndex - 1;
                int vsbMoveCost = (vsbLeftMoves > 0 && vsbRightMoves > 0) ? min(vsbLeftMoves, vsbRightMoves) : max(vsbLeftMoves, vsbRightMoves);
                vsbMinimumCost = min(vsbMinimumCost, vsbMoveCost);
            }
            vsbTotalCost += (vsbLong)vsbOverlapCount * vsbMinimumCost;
        }
    }

    // Check if the accumulated cost meets the target condition
    if (vsbValueMap.find(vsbTarget) != vsbValueMap.end()) {
        if (vsbTotalCost >= vsbValueMap[vsbTarget]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }

    // Calculate success rate for all keys
    int vsbValidKeyCount = 0, vsbTotalKeyCount = vsbValueMap.size();
    for (auto &vsbEntry : vsbValueMap) {
        if (vsbTotalCost >= vsbEntry.second) {
            vsbValidKeyCount++;
        }
    }

    // Output the success rate
    double vsbSuccessRate = (double)vsbValidKeyCount / vsbTotalKeyCount;
    cout << fixed << setprecision(2) << vsbSuccessRate;

    return 0;
}
