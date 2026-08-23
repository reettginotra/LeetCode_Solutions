#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty() || k == 0)
            return {};

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> heap;

        for (int i = 0; i < min((int)nums1.size(), k); i++)
            heap.emplace(nums1[i] + nums2[0], i, 0);

        vector<vector<int>> ans;

        while (!heap.empty() && k--) {
            auto [sum, i, j] = heap.top();
            heap.pop();

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size())
                heap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
        }

        return ans;
    }
};