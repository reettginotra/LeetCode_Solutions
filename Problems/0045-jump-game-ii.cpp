#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        int jumps = 0, reachable = 0, currReachable = 0;

        for (int i = 0; i < n - 1; i++) {
            if (i > reachable) return -1;

            reachable = max(reachable, i + A[i]);

            if (i == currReachable) {
                jumps++;
                currReachable = reachable;
            }
        }

        return currReachable >= n - 1 ? jumps : -1;
    }
};