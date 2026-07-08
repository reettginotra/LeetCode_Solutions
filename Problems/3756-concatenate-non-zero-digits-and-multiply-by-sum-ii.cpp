#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        int n = s.size();

        vector<int> pos, digit;
        vector<long long> preSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            preSum[i + 1] = preSum[i] + d;
            if (d) {
                pos.push_back(i);
                digit.push_back(d);
            }
        }

        int m = digit.size();

        vector<long long> pw(m + 1, 1), hash(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pw[i + 1] = (pw[i] * 10) % MOD;
            hash[i + 1] = (hash[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = preSum[r + 1] - preSum[l];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;
            int len = R - L + 1;

            long long x = (hash[R + 1] - hash[L] * pw[len]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};