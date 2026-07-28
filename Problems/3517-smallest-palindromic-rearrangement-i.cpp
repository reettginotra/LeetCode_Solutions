#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;

        string left, mid;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) mid = char('a' + i);
            left.append(cnt[i] / 2, char('a' + i));
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};