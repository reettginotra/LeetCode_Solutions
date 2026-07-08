#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    inline long long steps(long long n, long long a, long long b) {
        long long res = 0;
        while (a <= n) {
            res += min(n + 1LL, b) - a;
            a *= 10;
            b *= 10;
        }
        return res;
    }

    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;

        while (k) {
            long long cnt = steps(n, cur, cur + 1);

            if (cnt <= k) {
                cur++;
                k -= cnt;
            } else {
                cur *= 10;
                k--;
            }
        }

        return (int)cur;
    }
};