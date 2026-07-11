#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;

        for (char c : s)
            if (c != '-')
                t += toupper(c);

        string ans;
        int first = t.size() % k;
        int i = 0;

        if (first) {
            ans.append(t, 0, first);
            i = first;
        }

        while (i < (int)t.size()) {
            if (!ans.empty())
                ans += '-';
            ans.append(t, i, k);
            i += k;
        }

        return ans;
    }
};