#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int ans = 10, cur = 9, avail = 9;

        while (n > 1 && avail) {
            cur *= avail;
            ans += cur;
            avail--;
            n--;
        }

        return ans;
    }
};