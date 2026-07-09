#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// LeetCode solution starts from here
class Solution {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int smallSize = 0, largeSize = 0, k;

    void pruneSmall() {
        while (!small.empty()) {
            int x = small.top();
            auto it = delayed.find(x);
            if (it != delayed.end()) {
                if (--it->second == 0)
                    delayed.erase(it);
                small.pop();
            } else {
                break;
            }
        }
    }

    void pruneLarge() {
        while (!large.empty()) {
            int x = large.top();
            auto it = delayed.find(x);
            if (it != delayed.end()) {
                if (--it->second == 0)
                    delayed.erase(it);
                large.pop();
            } else {
                break;
            }
        }
    }

    void balance() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            pruneSmall();
        } else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            pruneLarge();
        }
    }

    void add(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        balance();
    }

    void remove(int num) {
        ++delayed[num];

        if (num <= small.top()) {
            --smallSize;
            if (num == small.top())
                pruneSmall();
        } else {
            --largeSize;
            if (!large.empty() && num == large.top())
                pruneLarge();
        }

        balance();
    }

    double getMedian() {
        if (k & 1)
            return (double)small.top();
        return ((double)small.top() + (double)large.top()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        this->k = k;
        vector<double> ans;

        for (int i = 0; i < k; ++i)
            add(nums[i]);

        ans.push_back(getMedian());

        for (int i = k; i < nums.size(); ++i) {
            add(nums[i]);
            remove(nums[i - k]);
            ans.push_back(getMedian());
        }

        return ans;
    }
};