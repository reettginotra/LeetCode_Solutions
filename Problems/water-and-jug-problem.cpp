#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == x || target == y || target == x + y) return true;
        return target % gcd(x, y) == 0;
    }
};