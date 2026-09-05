#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int left = 0, right = m;

        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if (l1 > r2)
                right = cut1 - 1;
            else
                left = cut1 + 1;
        }

        return 0.0;
    }
};

int main() {
    Solution sol;

    int m, n;
    cin >> m;

    vector<int> nums1(m);
    for (int& x : nums1)
        cin >> x;

    cin >> n;

    vector<int> nums2(n);
    for (int& x : nums2)
        cin >> x;

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}