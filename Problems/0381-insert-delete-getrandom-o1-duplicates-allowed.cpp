#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> pos;

    RandomizedCollection() {}

    bool insert(int val) {
        bool present = pos.count(val);

        arr.push_back(val);
        pos[val].insert(arr.size() - 1);

        return !present;
    }

    bool remove(int val) {
        if (!pos.count(val))
            return false;

        int idx = *pos[val].begin();
        pos[val].erase(idx);

        int last = arr.back();

        if (idx != (int)arr.size() - 1) {
            arr[idx] = last;

            pos[last].erase(arr.size() - 1);
            pos[last].insert(idx);
        }

        arr.pop_back();

        if (pos[val].empty())
            pos.erase(val);

        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
