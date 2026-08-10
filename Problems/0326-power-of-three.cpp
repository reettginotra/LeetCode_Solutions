#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;

        while (n % 3 == 0)
            n /= 3;

        return n == 1;
    }
};