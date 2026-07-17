#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;

        for (int i = 1; i < timeSeries.size(); i++)
            ans += min(duration, timeSeries[i] - timeSeries[i - 1]);

        return ans + duration;
    }
};