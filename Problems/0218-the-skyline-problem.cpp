#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<array<int, 3>> events;

        for (auto& b : buildings) {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], 0, 0});
        }

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> heap;
        heap.push({0, INT_MAX});

        vector<vector<int>> res;

        for (auto& e : events) {
            int x = e[0], negH = e[1], right = e[2];

            while (!heap.empty() && heap.top().second <= x)
                heap.pop();

            if (negH)
                heap.push({-negH, right});

            int height = heap.top().first;

            if (res.empty() || res.back()[1] != height)
                res.push_back({x, height});
        }

        return res;
    }
};