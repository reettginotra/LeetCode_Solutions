#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) return false;

        int target = sum / 2;
        vector<char> dp(target + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int j = target; j >= x; j--)
                dp[j] |= dp[j - x];
        }

        return dp[target];
    }
};