#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        for (int i = 0; i < 26 && freq[i]; i++)
            ans += freq[i] * (i / 8 + 1);

        return ans;
    }
};