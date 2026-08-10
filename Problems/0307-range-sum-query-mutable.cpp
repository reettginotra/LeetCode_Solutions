#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class NumArray {
public:
    int n;
    vector<int> tree;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            tree[node] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, 2 * node, l, mid);
        build(nums, 2 * node + 1, mid + 1, r);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateHelper(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            updateHelper(2 * node, l, mid, idx, val);
        else
            updateHelper(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        if (r < ql || l > qr)
            return 0;

        int mid = l + (r - l) / 2;

        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int index, int val) {
        updateHelper(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};