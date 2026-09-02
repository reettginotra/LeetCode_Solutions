#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.reserve(n);
        int cur = 1;

        for (int i = 0; i < n; i++) {
            ans.push_back(cur);

            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur + 1 > n)
                    cur /= 10;
                cur++;
            }
        }

        return ans;
    }
};
