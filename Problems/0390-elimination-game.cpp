#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        bool left = true;

        while (n > 1) {
            if (left || (n & 1))
                head += step;

            step <<= 1;
            n >>= 1;
            left = !left;
        }

        return head;
    }
};