#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> pos;

    RandomizedSet() {}

    bool insert(int val) {
        if (pos.count(val))
            return false;

        pos[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!pos.count(val))
            return false;

        int idx = pos[val];
        int last = arr.back();

        arr[idx] = last;
        pos[last] = idx;

        arr.pop_back();
        pos.erase(val);

        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
