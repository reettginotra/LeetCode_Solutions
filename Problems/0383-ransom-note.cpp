#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {};

        for (char c : magazine)
            cnt[c - 'a']++;

        for (char c : ransomNote) {
            int idx = c - 'a';

            if (--cnt[idx] < 0)
                return false;
        }

        return true;
    }
};