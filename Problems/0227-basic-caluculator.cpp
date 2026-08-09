#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long last = 0;
        long long result = 0;
        char op = '+';

        for (int i = 0; i <= s.size(); i++) {
            char ch = (i < s.size() ? s[i] : '+');

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            if ((!isdigit(ch) && ch != ' ') || i == s.size()) {
                if (op == '+') {
                    result += last;
                    last = num;
                } else if (op == '-') {
                    result += last;
                    last = -num;
                } else if (op == '*') {
                    last *= num;
                } else {
                    result += last;
                    last = last / num;
                }

                op = ch;
                num = 0;
            }
        }

        return result + last;
    }
};