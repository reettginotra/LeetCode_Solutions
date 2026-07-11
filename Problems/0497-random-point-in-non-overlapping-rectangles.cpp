#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
    vector<vector<int>> rects;
    vector<int> prefix;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int sum = 0;
        for (auto &r : rects) {
            sum += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            prefix.push_back(sum);
        }
    }

    vector<int> pick() {
        int k = rand() % prefix.back() + 1;
        int idx = lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin();

        auto &r = rects[idx];

        int base = idx == 0 ? 0 : prefix[idx - 1];
        int offset = k - base - 1;

        int width = r[2] - r[0] + 1;

        return {
            r[0] + offset % width,
            r[1] + offset / width
        };
    }
};