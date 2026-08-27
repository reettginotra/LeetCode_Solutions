#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Solution {
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> arr = original;

        for (int i = arr.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }

        return arr;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution sol(nums);

    vector<int> shuffled = sol.shuffle();

    for (int x : shuffled)
        cout << x << " ";

    cout << "\n";

    vector<int> reset = sol.reset();

    for (int x : reset)
        cout << x << " ";

    cout << "\n";

    return 0;
}