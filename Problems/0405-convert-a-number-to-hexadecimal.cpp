#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        const string hex = "0123456789abcdef";
        string ans;
        unsigned int n = num;

        while (n) {
            ans.push_back(hex[n & 15]);
            n >>= 4;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};