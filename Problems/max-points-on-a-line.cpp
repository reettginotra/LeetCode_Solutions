#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <numeric>

using namespace std;

//leetcode sol starts from here
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int curMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }

                string key = to_string(dx) + "/" + to_string(dy);
                curMax = max(curMax, ++mp[key]);
            }

            ans = max(ans, curMax + 1);
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> points = {
        {1,1},
        {3,2},
        {5,3},
        {4,1},
        {2,3},
        {1,4}
    };

    Solution obj;
    cout << "Maximum Points on a Line: " << obj.maxPoints(points) << endl;

    return 0;
}