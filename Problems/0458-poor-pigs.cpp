#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1)
            return 0;

        int states = minutesToTest / minutesToDie + 1;
        int pigs = 0;
        long long power = 1;

        while (power < buckets) {
            pigs++;
            power *= states;
        }

        return pigs;
    }
};