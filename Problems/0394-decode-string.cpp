#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stack;
        string cur = "";
        int num = 0;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                stack.push({cur, num});
                cur = "";
                num = 0;
            }
            else if (c == ']') {
                auto [prev, cnt] = stack.top();
                stack.pop();

                string temp = "";
                for (int i = 0; i < cnt; i++)
                    temp += cur;

                cur = prev + temp;
            }
            else {
                cur += c;
            }
        }

        return cur;
    }
};

int main() {
    Solution sol;

    string s = "3[a2[c]]";

    cout << sol.decodeString(s) << endl;

    return 0;
}