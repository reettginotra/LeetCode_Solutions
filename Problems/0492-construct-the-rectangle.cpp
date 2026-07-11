#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);

        while (area % w)
            --w;

        return {area / w, w};
    }
};