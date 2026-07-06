#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cur = 0;

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                cur++;
                ans += cur;
            } else {
                cur = 0;
            }
        }

        return ans;
    }
};