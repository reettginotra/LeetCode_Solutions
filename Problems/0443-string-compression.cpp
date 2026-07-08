#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, read = 0;

        while (read < n) {
            char c = chars[read];
            int start = read;

            while (read < n && chars[read] == c)
                read++;

            chars[write++] = c;

            int cnt = read - start;
            if (cnt > 1) {
                int x = cnt;
                char buf[4];
                int len = 0;

                while (x) {
                    buf[len++] = char('0' + x % 10);
                    x /= 10;
                }

                while (len)
                    chars[write++] = buf[--len];
            }
        }

        return write;
    }
};