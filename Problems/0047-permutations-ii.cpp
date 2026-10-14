#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, cur, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& result) {
        if (cur.size() == nums.size()) {
            result.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }

            used[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, used, cur, result);
            cur.pop_back();
            used[i] = false;
        }
    }
};