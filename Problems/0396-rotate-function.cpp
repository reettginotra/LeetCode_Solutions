#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long total = 0, cur = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            cur += 1LL * i * nums[i];
        }

        long long ans = cur;

        for (int i = n - 1; i > 0; i--) {
            cur += total - 1LL * n * nums[i];
            ans = max(ans, cur);
        }

        return ans;
    }
};
