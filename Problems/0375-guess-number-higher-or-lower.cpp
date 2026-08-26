#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int length = 2; length <= n; length++) {
            for (int left = 1; left <= n - length + 1; left++) {
                int right = left + length - 1;
                dp[left][right] = INT_MAX;

                for (int x = left; x <= right; x++) {
                    dp[left][right] = min(
                        dp[left][right],
                        x + max(dp[left][x - 1], dp[x + 1][right])
                    );
                }
            }
        }

        return dp[1][n];
    }
};

