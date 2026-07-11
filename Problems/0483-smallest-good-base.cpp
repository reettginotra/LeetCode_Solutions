#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoull(n);
        int maxM = log2(num);

        for (int m = maxM; m >= 1; --m) {
            unsigned long long l = 2, r = pow(num, 1.0 / m) + 1;

            while (l <= r) {
                unsigned long long k = l + (r - l) / 2;
                __int128 sum = 1, cur = 1;

                for (int i = 1; i <= m; ++i) {
                    cur *= k;
                    sum += cur;
                    if (sum > num) break;
                }

                if (sum == num)
                    return to_string(k);

                if (sum < num)
                    l = k + 1;
                else
                    r = k - 1;
            }
        }

        return to_string(num - 1);
    }
};