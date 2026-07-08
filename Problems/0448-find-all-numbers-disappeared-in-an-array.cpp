#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};