#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned carry = (unsigned)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};