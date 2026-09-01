#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                 vector<double>& values,
                                 vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];

            graph[a].push_back({b, v});
            graph[b].push_back({a, 1.0 / v});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string src = q[0], dst = q[1];

            if (!graph.count(src) || !graph.count(dst)) {
                ans.push_back(-1.0);
                continue;
            }

            if (src == dst) {
                ans.push_back(1.0);
                continue;
            }

            queue<pair<string, double>> bfs;
            unordered_set<string> vis;

            bfs.push({src, 1.0});
            vis.insert(src);

            double result = -1.0;

            while (!bfs.empty()) {
                auto [node, value] = bfs.front();
                bfs.pop();

                if (node == dst) {
                    result = value;
                    break;
                }

                for (auto &[next, weight] : graph[node]) {
                    if (!vis.count(next)) {
                        vis.insert(next);
                        bfs.push({next, value * weight});
                    }
                }
            }

            ans.push_back(result);
        }

        return ans;
    }
};

