#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int ans = 0;
        int right = -1;

        for (auto& v : intervals) {
            if (v[1] > right) {
                ans++;
                right = v[1];
            }
        }

        return ans;
    }
};