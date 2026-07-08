#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int, int>> starts;
        starts.reserve(n);

        for (int i = 0; i < n; i++)
            starts.push_back({intervals[i][0], i});

        sort(starts.begin(), starts.end());

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(
                starts.begin(),
                starts.end(),
                make_pair(intervals[i][1], -1)
            );

            ans[i] = (it == starts.end()) ? -1 : it->second;
        }

        return ans;
    }
};