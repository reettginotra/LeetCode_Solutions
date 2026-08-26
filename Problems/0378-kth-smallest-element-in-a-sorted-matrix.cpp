#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        auto count = [&](int x) {
            int i = n - 1, j = 0, cnt = 0;

            while (i >= 0 && j < n) {
                if (matrix[i][j] <= x) {
                    cnt += i + 1;
                    j++;
                } else {
                    i--;
                }
            }

            return cnt;
        };

        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (count(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};

