#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;

        vector<int> s(n + 2);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int head = 2, tail = 3, num = 1, ans = 1;

        while (tail < n) {
            for (int i = 0; i < s[head] && tail < n; i++) {
                s[tail] = num;
                if (num == 1) ans++;
                tail++;
            }
            num = 3 - num;
            head++;
        }

        return ans;
    }
};