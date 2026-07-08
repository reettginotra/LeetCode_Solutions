#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        unordered_map<int, int> cnt;
        cnt.reserve(n * 2);

        for (int i = 0; i < n; i++) {
            cnt.clear();

            int x = points[i][0];
            int y = points[i][1];

            for (int j = 0; j < n; j++) {
                int dx = x - points[j][0];
                int dy = y - points[j][1];
                ++cnt[dx * dx + dy * dy];
            }

            for (auto &p : cnt)
                ans += p.second * (p.second - 1);
        }

        return ans;
    }
};