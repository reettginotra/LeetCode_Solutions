#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;

        for (int a : nums1)
            for (int b : nums2)
                mp[a + b]++;

        int ans = 0;

        for (int c : nums3)
            for (int d : nums4) {
                auto it = mp.find(-(c + d));
                if (it != mp.end())
                    ans += it->second;
            }

        return ans;
    }
};