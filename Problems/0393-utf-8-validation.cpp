#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rem = 0;

        for (int b : data) {
            if (rem == 0) {
                if ((b >> 7) == 0)
                    continue;
                else if ((b >> 5) == 0b110)
                    rem = 1;
                else if ((b >> 4) == 0b1110)
                    rem = 2;
                else if ((b >> 3) == 0b11110)
                    rem = 3;
                else
                    return false;
            } else {
                if ((b >> 6) != 0b10)
                    return false;

                rem--;
            }
        }

        return rem == 0;
    }
};

