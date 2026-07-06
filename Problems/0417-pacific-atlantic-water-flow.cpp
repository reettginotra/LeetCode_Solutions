#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        queue<pair<int, int>> qp, qa;
        vector<vector<char>> pac(m, vector<char>(n, 0));
        vector<vector<char>> atl(m, vector<char>(n, 0));

        for (int i = 0; i < m; i++) {
            qp.push({i, 0});
            qa.push({i, n - 1});
            pac[i][0] = 1;
            atl[i][n - 1] = 1;
        }

        for (int j = 0; j < n; j++) {
            qp.push({0, j});
            qa.push({m - 1, j});
            pac[0][j] = 1;
            atl[m - 1][j] = 1;
        }

        int d[5] = {-1, 0, 1, 0, -1};

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<char>>& vis) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                int x = cur.first;
                int y = cur.second;

                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k];
                    int ny = y + d[k + 1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny])
                        continue;
                    if (heights[nx][ny] < heights[x][y])
                        continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        };

        bfs(qp, pac);
        bfs(qa, atl);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};