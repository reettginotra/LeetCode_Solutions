#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> need(26, 0), window(26, 0), ans;

        for (char c : p)
            need[c - 'a']++;

        for (int i = 0; i < n; i++) {
            window[s[i] - 'a']++;

            if (i >= m)
                window[s[i - m] - 'a']--;

            if (window == need)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};