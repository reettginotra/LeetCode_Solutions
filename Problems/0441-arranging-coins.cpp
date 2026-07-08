#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, r = n;

        while (l <= r) {
            long long m = l + ((r - l) >> 1);
            long long sum = m * (m + 1) / 2;

            if (sum == n)
                return m;

            if (sum < n)
                l = m + 1;
            else
                r = m - 1;
        }

        return (int)r;
    }
};