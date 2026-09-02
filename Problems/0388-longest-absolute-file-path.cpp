#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> depth_len;
        depth_len[0] = 0;
        int ans = 0;

        stringstream ss(input);
        string s;

        while (getline(ss, s, '\n')) {
            int depth = 0;

            while (depth < s.size() && s[depth] == '\t')
                depth++;

            string name = s.substr(depth);

            if (name.find('.') != string::npos) {
                ans = max(ans, depth_len[depth] + (int)name.size());
            } else {
                depth_len[depth + 1] =
                    depth_len[depth] + (int)name.size() + 1;
            }
        }

        return ans;
    }
};
