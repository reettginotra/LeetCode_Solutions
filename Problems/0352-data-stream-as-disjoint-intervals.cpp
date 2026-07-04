#include <bits/stdc++.h>
using namespace std;

//leetcode sol starts from here
class SummaryRanges {
    map<int, int> mp;

public:
    void addNum(int value) {
        auto it = mp.upper_bound(value);

        if (it != mp.begin()) {
            auto pre = prev(it);
            if (pre->second >= value) return;
        }

        int l = value, r = value;

        if (it != mp.begin()) {
            auto pre = prev(it);
            if (pre->second + 1 == value) {
                l = pre->first;
                r = max(r, pre->second);
                mp.erase(pre);
            }
        }

        if (it != mp.end() && it->first == value + 1) {
            r = it->second;
            mp.erase(it);
        }

        mp[l] = r;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto &[l, r] : mp)
            ans.push_back({l, r});
        return ans;
    }
};
