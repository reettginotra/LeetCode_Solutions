#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

//leetcode sol starts from here
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;

        for (int price : prices) {
            hold1 = max(hold1, -price);
            release1 = max(release1, hold1 + price);
            hold2 = max(hold2, release1 - price);
            release2 = max(release2, hold2 + price);
        }

        return release2;
    }
};
