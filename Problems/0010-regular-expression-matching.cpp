#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool isMatch(string s, string p) {
        int k = 3;
        vector<vector<bool>> result(k, vector<bool>(p.length() + 1, false));

        result[0][0] = true;

        for (int i = 2; i <= p.length(); ++i) {
            if (p[i - 1] == '*') {
                result[0][i] = result[0][i - 2];
            }
        }

        for (int i = 1; i <= s.length(); ++i) {
            if (i > 1) {
                result[0][0] = false;
            }

            for (int j = 1; j <= p.length(); ++j) {
                if (p[j - 1] != '*') {
                    result[i % k][j] =
                        result[(i - 1) % k][j - 1] &&
                        (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                else {
                    result[i % k][j] =
                        result[i % k][j - 2] ||
                        (result[(i - 1) % k][j] &&
                         (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }

        return result[s.length() % k][p.length()];
    }
};