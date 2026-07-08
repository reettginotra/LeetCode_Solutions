#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++)
            dp[i].reserve(i + 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)nums[i] - nums[j];

                auto it = dp[j].find(d);
                int cnt = (it == dp[j].end()) ? 0 : it->second;

                ans += cnt;
                dp[i][d] += cnt + 1;
            }
        }

        return ans;
    }
};