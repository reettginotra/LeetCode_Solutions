#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<char>> dp(4, vector<char>(MAXX));
        dp[0][0] = 1;

        for (int x : nums) {
            for (int k = 2; k >= 0; --k) {
                for (int v = 0; v < MAXX; ++v) {
                    if (dp[k][v])
                        dp[k + 1][v ^ x] = 1;
                }
            }
        }

        vector<char> vis(MAXX);

        for (int x : nums)
            vis[x] = 1;

        for (int v = 0; v < MAXX; ++v)
            if (dp[3][v])
                vis[v] = 1;

        return accumulate(vis.begin(), vis.end(), 0);
    }
};