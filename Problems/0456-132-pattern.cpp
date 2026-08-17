#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> stack;
        int third = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i];

            if (x < third)
                return true;

            while (!stack.empty() && x > stack.back()) {
                third = stack.back();
                stack.pop_back();
            }

            stack.push_back(x);
        }

        return false;
    }
};