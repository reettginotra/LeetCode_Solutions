#include <bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    vector<int> lis;

    for (auto &e : envelopes) {
        auto it = lower_bound(lis.begin(), lis.end(), e[1]);
        if (it == lis.end())
            lis.push_back(e[1]);
        else
            *it = e[1];
    }

    return lis.size();
}
