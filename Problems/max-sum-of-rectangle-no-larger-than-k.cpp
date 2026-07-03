#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        if (m > n) {
            vector<vector<int>> t(n, vector<int>(m));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    t[j][i] = matrix[i][j];
            swap(matrix, t);
            swap(m, n);
        }

        int ans = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> sum(m, 0);

            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++)
                    sum[i] += matrix[i][right];

                set<int> s;
                s.insert(0);
                int cur = 0;

                for (int x : sum) {
                    cur += x;
                    auto it = s.lower_bound(cur - k);
                    if (it != s.end())
                        ans = max(ans, cur - *it);
                    s.insert(cur);
                }
            }
        }

        return ans;
    }
};
