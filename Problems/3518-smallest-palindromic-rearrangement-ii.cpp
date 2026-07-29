#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid;
        int m = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid += char('a' + i);
            half[i] = freq[i] / 2;
            m += half[i];
        }

        auto comb = [&](int n, int r) {
            if (r > n) return 0LL;
            r = min(r, n - r);
            long long ans = 1;
            for (int i = 1; i <= r; i++) {
                ans = ans * (n - r + i) / i;
                if (ans > k) return (long long)k + 1;
            }
            return ans;
        };

        auto getWays = [&](vector<int> &f) {
            long long ways = 1;
            int len = 0;

            for (int i = 0; i < 26; i++) {
                if (f[i]) {
                    len += f[i];
                    ways *= comb(len, f[i]);
                    if (ways > k)
                        return (long long)k + 1;
                }
            }

            return ways;
        };

        if (getWays(half) < k)
            return "";

        string left;

        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (!half[c]) continue;

                half[c]--;

                long long ways = getWays(half);

                if (ways >= k) {
                    left += char('a' + c);
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};