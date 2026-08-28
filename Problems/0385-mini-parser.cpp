#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
    bool isInt;
    int value;
    vector<NestedInteger> list;

public:
    NestedInteger() {
        isInt = false;
        value = 0;
    }

    NestedInteger(int value) {
        isInt = true;
        this->value = value;
    }

    bool isInteger() const {
        return isInt;
    }

    void add(const NestedInteger& elem) {
        if (isInt) {
            isInt = false;
            list.clear();
        }
        list.push_back(elem);
    }

    void setInteger(int value) {
        isInt = true;
        this->value = value;
        list.clear();
    }

    int getInteger() const {
        return value;
    }

    const vector<NestedInteger>& getList() const {
        return list;
    }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[')
            return NestedInteger(stoi(s));

        vector<NestedInteger> stack;
        int num = 0, sign = 1;
        bool hasNum = false;

        for (char c : s) {
            if (c == '[') {
                stack.push_back(NestedInteger());
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                hasNum = true;
            }
            else if (c == ',' || c == ']') {
                if (hasNum) {
                    stack.back().add(NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    hasNum = false;
                }

                if (c == ']' && stack.size() > 1) {
                    NestedInteger cur = stack.back();
                    stack.pop_back();
                    stack.back().add(cur);
                }
            }
        }

        return stack[0];
    }
};
