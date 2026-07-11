#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        int cnt = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);

        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j])
                j++;
            cnt += j - (mid + 1);
        }

        vector<int> tmp;
        tmp.reserve(r - l + 1);

        int i = l;
        j = mid + 1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j])
                tmp.push_back(nums[i++]);
            else
                tmp.push_back(nums[j++]);
        }

        while (i <= mid)
            tmp.push_back(nums[i++]);

        while (j <= r)
            tmp.push_back(nums[j++]);

        copy(tmp.begin(), tmp.end(), nums.begin() + l);

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};