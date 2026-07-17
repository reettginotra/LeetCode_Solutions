#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums)
            freq[x]++;

        vector<int> cnt(mx + 1);

        for (int d = 1; d <= mx; d++)
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];

        vector<long long> exact(mx + 1);

        for (int d = mx; d >= 1; d--) {
            exact[d] = 1LL * cnt[d] * (cnt[d] - 1) / 2;
            for (int m = d + d; m <= mx; m += d)
                exact[d] -= exact[m];
        }

        vector<long long> pref(mx + 1);

        for (int d = 1; d <= mx; d++)
            pref[d] = pref[d - 1] + exact[d];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries)
            ans.push_back(lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin());

        return ans;
    }
};