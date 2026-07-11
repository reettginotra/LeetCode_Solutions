#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum || ((sum + target) & 1))
            return 0;

        int t = (sum + target) / 2;

        vector<int> dp(t + 1);
        dp[0] = 1;

        for (int x : nums) {
            for (int j = t; j >= x; --j)
                dp[j] += dp[j - x];
        }

        return dp[t];
    }
};