#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (n < 2 || stones[1] != 1)
            return false;

        unordered_map<int, int> idx;
        idx.reserve(n * 2);

        for (int i = 0; i < n; i++)
            idx[stones[i]] = i;

        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int k : dp[i]) {
                for (int d = k - 1; d <= k + 1; d++) {
                    if (d <= 0) continue;

                    auto it = idx.find(stones[i] + d);
                    if (it == idx.end()) continue;

                    if (it->second == n - 1)
                        return true;

                    dp[it->second].insert(d);
                }
            }
        }

        return n == 1;
    }
};