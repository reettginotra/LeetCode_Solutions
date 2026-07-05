#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });

        vector<vector<int>> ans;

        for (auto& p : people)
            ans.insert(ans.begin() + p[1], p);

        return ans;
    }
};