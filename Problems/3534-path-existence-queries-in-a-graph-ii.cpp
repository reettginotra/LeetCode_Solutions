#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        unordered_map<int, int> pos;
        pos.reserve(m * 2);
        for (int i = 0; i < m; i++)
            pos[vals[i]] = i;

        vector<int> nxt(m);
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j + 1 < m && vals[j + 1] - vals[i] <= maxDiff)
                ++j;
            nxt[i] = j;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(m));

        for (int i = 0; i < m; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < m; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int a = nums[u], b = nums[v];

            if (a == b) {
                ans.push_back(1);
                continue;
            }

            if (a > b)
                swap(a, b);

            int l = pos[a];
            int r = pos[b];

            if (up[LOG - 1][l] < r) {
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < r) {
                    cur = up[k][cur];
                    dist += 1 << k;
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};