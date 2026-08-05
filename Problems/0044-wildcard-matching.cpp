#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    bool isMatch(string s, string p) {
        int sPtr = 0, pPtr = 0;
        int lastSPtr = -1, lastPPtr = -1;

        while (sPtr < s.size()) {
            if (pPtr < p.size() && (p[pPtr] == '?' || p[pPtr] == s[sPtr])) {
                sPtr++;
                pPtr++;
            } 
            else if (pPtr < p.size() && p[pPtr] == '*') {
                pPtr++;
                lastSPtr = sPtr;
                lastPPtr = pPtr;
            } 
            else if (lastPPtr != -1) {
                lastSPtr++;
                sPtr = lastSPtr;
                pPtr = lastPPtr;
            } 
            else {
                return false;
            }
        }

        while (pPtr < p.size() && p[pPtr] == '*')
            pPtr++;

        return pPtr == p.size();
    }
};