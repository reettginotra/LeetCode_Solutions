#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        cnt.reserve(128);

        int n = s.size();

        for (char c : s)
            cnt[c]++;

        vector<string> bucket(n + 1);

        for (auto &p : cnt)
            bucket[p.second].append(p.second, p.first);

        string ans;
        ans.reserve(n);

        for (int i = n; i >= 1; i--)
            ans += bucket[i];

        return ans;
    }
};