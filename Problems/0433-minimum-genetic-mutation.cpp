#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        if (!st.count(endGene))
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        char ch[] = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            string s = cur.first;
            int step = cur.second;

            if (s == endGene)
                return step;

            for (int i = 0; i < 8; i++) {
                char old = s[i];

                for (char c : ch) {
                    if (c == old)
                        continue;

                    s[i] = c;

                    if (st.count(s)) {
                        st.erase(s);
                        q.push({s, step + 1});
                    }
                }

                s[i] = old;
            }
        }

        return -1;
    }
};