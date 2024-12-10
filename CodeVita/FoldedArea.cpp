#include <bits/stdc++.h>
using namespace std;

// Function to calculate reflection of a point
pair<double, double> computeReflection(double px, double py, double lx1, double ly1, double lx2, double ly2) {
    double slopeDiff = ly2 - ly1;
    double constantDiff = lx1 - lx2;
    double lineConst = lx2 * ly1 - lx1 * ly2;
    double dist = (slopeDiff * px + constantDiff * py + lineConst) / sqrt(slopeDiff * slopeDiff + constantDiff * constantDiff);
    double reflectedX = px - 2 * dist * (slopeDiff / sqrt(slopeDiff * slopeDiff + constantDiff * constantDiff));
    double reflectedY = py - 2 * dist * (constantDiff / sqrt(slopeDiff * slopeDiff + constantDiff * constantDiff));
    return {reflectedX, reflectedY};
}

// Function to generate points and compute reflections
set<pair<double, double>> calculatePoints(double area, double lx1, double ly1, double lx2, double ly2) {
    double sideLength = sqrt(area);
    vector<pair<double, double>> basePoints = {
        {0, 0},
        {0, sideLength},
        {sideLength, sideLength},
        {sideLength, 0},
    };

    set<pair<double, double>> uniquePoints(basePoints.begin(), basePoints.end());

    for (const auto& point : basePoints) {
        auto [refX, refY] = computeReflection(point.first, point.second, lx1, ly1, lx2, ly2);
        uniquePoints.insert({refX, refY});
    }
    return uniquePoints;
}

int main() {
    double areaInput;
    cin >> areaInput;

    double lineX1, lineY1, lineX2, lineY2;
    cin >> lineX1 >> lineY1 >> lineX2 >> lineY2;

    set<pair<double, double>> points = calculatePoints(areaInput, lineX1, lineY1, lineX2, lineY2);

    for (const auto& point : points) {
        cout << fixed << setprecision(2) << point.first << " " << point.second << endl;
    }

    return 0;
}
