#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    static const int MOD = 1000000007;

    int subsequencePairCount(vector<int>& nums) {
        unordered_map<int, int> dp, ndp;
        dp[0] = 1;

        for (int x : nums) {
            ndp = dp;

            for (auto &[state, ways] : dp) {
                int g1 = state / 201;
                int g2 = state % 201;

                int ng1 = g1 ? gcd(g1, x) : x;
                int ng2 = g2 ? gcd(g2, x) : x;

                int s1 = ng1 * 201 + g2;
                int s2 = g1 * 201 + ng2;

                ndp[s1] = (ndp[s1] + ways) % MOD;
                ndp[s2] = (ndp[s2] + ways) % MOD;
            }

            dp.swap(ndp);
        }

        long long ans = 0;

        for (auto &[state, ways] : dp) {
            int g1 = state / 201;
            int g2 = state % 201;

            if (g1 && g1 == g2)
                ans = (ans + ways) % MOD;
        }

        return (int)ans;
    }
};