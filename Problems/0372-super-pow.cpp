#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
    static const int MOD = 1337;

    int modPow(int a, int b) {
        int res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= MOD;

        for (int d : b)
            ans = modPow(ans, 10) * modPow(a, d) % MOD;

        return ans;
    }
};