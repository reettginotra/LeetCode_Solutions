#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> corners;
        long long area = 0;

        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = INT_MIN, y2 = INT_MIN;

        for (auto& r : rectangles) {
            int x = r[0], y = r[1];
            int a = r[2], b = r[3];

            x1 = min(x1, x);
            y1 = min(y1, y);
            x2 = max(x2, a);
            y2 = max(y2, b);

            area += 1LL * (a - x) * (b - y);

            pair<int, int> points[] = {
                {x, y},
                {x, b},
                {a, y},
                {a, b}
            };

            for (auto p : points) {
                if (corners.count(p))
                    corners.erase(p);
                else
                    corners.insert(p);
            }
        }

        if (area != 1LL * (x2 - x1) * (y2 - y1))
            return false;

        set<pair<int, int>> expected = {
            {x1, y1},
            {x1, y2},
            {x2, y1},
            {x2, y2}
        };

        return corners == expected;
    }
};