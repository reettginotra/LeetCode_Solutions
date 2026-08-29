#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.size();

        for (int target = 1; target <= 26; target++) {
            int cnt[26] = {};
            int left = 0, right = 0;
            int unique = 0, atLeastK = 0;

            while (right < n) {
                int idx = s[right] - 'a';

                if (cnt[idx] == 0)
                    unique++;

                cnt[idx]++;

                if (cnt[idx] == k)
                    atLeastK++;

                right++;

                while (unique > target) {
                    idx = s[left] - 'a';

                    if (cnt[idx] == k)
                        atLeastK--;

                    cnt[idx]--;

                    if (cnt[idx] == 0)
                        unique--;

                    left++;
                }

                if (unique == target && unique == atLeastK)
                    ans = max(ans, right - left);
            }
        }

        return ans;
    }
};
