#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> a;
        a.reserve(n);

        int mx = 0;

        for (int x : nums) {
            mx = max(mx, x);
            a.push_back(gcd(mx, x));
        }

        sort(a.begin(), a.end());

        long long ans = 0;

        for (int i = 0, j = n - 1; i < j; ++i, --j)
            ans += gcd(a[i], a[j]);

        return ans;
    }
};