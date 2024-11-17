#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// Point structure
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Line structure
struct Line {
    Point start, end;

    Line(int x1, int y1, int x2, int y2) {
        if (x1 < x2 || (x1 == x2 && y1 < y2)) {
            start = Point(x1, y1);
            end = Point(x2, y2);
        } else {
            start = Point(x2, y2);
            end = Point(x1, y1);
        }
    }

    bool containsPoint(const Point& p) const {
        if (!isPointInBoundingBox(p)) return false;
        if (start.x == end.x) return p.x == start.x; // Vertical line
        if (start.y == end.y) return p.y == start.y; // Horizontal line
        // Check if point is on the line using slope
        return (end.y - start.y) * (p.x - start.x) ==
               (end.x - start.x) * (p.y - start.y);
    }

    bool isPointInBoundingBox(const Point& p) const {
        return p.x >= min(start.x, end.x) && p.x <= max(start.x, end.x) &&
               p.y >= min(start.y, end.y) && p.y <= max(start.y, end.y);
    }

    int getLengthToEnd(const Point& p, bool toStart) const {
        Point target = toStart ? start : end;
        return max(abs(p.x - target.x), abs(p.y - target.y));
    }

    vector<int> getIntensities(const Point& p) const {
        vector<int> intensities;
        if (p == start || p == end) {
            intensities.push_back(getLengthToEnd(p, !(p == start)));
        } else if (containsPoint(p)) {
            intensities.push_back(getLengthToEnd(p, true));
            intensities.push_back(getLengthToEnd(p, false));
        }
        return intensities;
    }
};

// Solve Magic Stars
int solveMagicStars(const vector<Line>& lines, int k) {
    map<Point, set<int>> intersections;

    // Find intersections
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            Point p(x, y);
            for (size_t i = 0; i < lines.size(); i++) { // Use size_t for unsigned comparison
                if (lines[i].containsPoint(p)) {
                    intersections[p].insert(i);
                }
            }
        }
    }

    int totalIntensity = 0;

    // Calculate total intensity for intersections
    for (const auto& entry : intersections) {
        if (static_cast<int>(entry.second.size()) == k) { // Cast size to int for comparison
            vector<int> intensities;
            for (int lineIndex : entry.second) {
                vector<int> lineIntensities = lines[lineIndex].getIntensities(entry.first);
                intensities.insert(intensities.end(), lineIntensities.begin(), lineIntensities.end());
            }
            if (!intensities.empty()) {
                totalIntensity += *min_element(intensities.begin(), intensities.end());
            }
        }
    }
    return totalIntensity;
}

// Main function
int main() {
    int n;
    cin >> n;
    vector<Line> lines;

    // Input lines
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back(Line(x1, y1, x2, y2));
    }

    int k;
    cin >> k;

    // Output result
    cout << solveMagicStars(lines, k) << endl;

    return 0;
}