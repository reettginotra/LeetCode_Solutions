#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1), parent(n, -1);
        int mx = 1, idx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }

        vector<int> ans;
        while (idx != -1) {
            ans.push_back(nums[idx]);
            idx = parent[idx];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};