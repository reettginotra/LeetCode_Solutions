#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < mn)
                mn = nums[i];

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
            ans += nums[i] - mn;

        return (int)ans;
    }
};