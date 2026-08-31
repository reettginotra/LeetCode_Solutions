#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> pos;

public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            pos[nums[i]].push_back(i);
    }

    int pick(int target) {
        vector<int>& v = pos[target];
        return v[rand() % v.size()];
    }
};
