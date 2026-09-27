#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        if (A.empty()) return 0;

        int last = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[last] != A[i]) {
                last++;
                A[last] = A[i];
            }
        }
        return last + 1;
    }
};