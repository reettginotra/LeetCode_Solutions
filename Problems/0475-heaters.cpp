#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans = 0, j = 0, m = heaters.size();

        for (int house : houses) {
            while (j + 1 < m &&
                   abs(heaters[j + 1] - house) <= abs(heaters[j] - house))
                j++;

            ans = max(ans, abs(heaters[j] - house));
        }

        return ans;
    }
};