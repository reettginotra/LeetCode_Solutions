#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            int hc = __builtin_popcount(h);

            for (int m = 0; m < 60; m++) {
                if (hc + __builtin_popcount(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10)
                        time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};