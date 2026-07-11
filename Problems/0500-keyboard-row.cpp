#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> row(26);

        for (char c : string("qwertyuiop")) row[c - 'a'] = 1;
        for (char c : string("asdfghjkl")) row[c - 'a'] = 2;
        for (char c : string("zxcvbnm")) row[c - 'a'] = 3;

        vector<string> ans;

        for (string &w : words) {
            int r = row[tolower(w[0]) - 'a'];
            bool ok = true;

            for (char c : w) {
                if (row[tolower(c) - 'a'] != r) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(w);
        }

        return ans;
    }
};