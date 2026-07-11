#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;

        for (int x : nums) {
            if (x)
                ans = max(ans, ++cnt);
            else
                cnt = 0;
        }

        return ans;
    }
};