#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {};
        int left = 0, best = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            int idx = s[right] - 'A';
            best = max(best, ++cnt[idx]);

            while (right - left + 1 - best > k)
                cnt[s[left++] - 'A']--;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};