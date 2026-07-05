#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = 0, right = 0;

        for (int x : nums) {
            left = max(left, (long long)x);
            right += x;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;

            int cnt = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    cnt++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if (cnt > k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};