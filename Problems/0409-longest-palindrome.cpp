#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[128] = {};
        
        for (char c : s)
            cnt[c]++;

        int ans = 0;
        bool odd = false;

        for (int x : cnt) {
            ans += x & ~1;
            if (x & 1)
                odd = true;
        }

        return ans + odd;
    }
};