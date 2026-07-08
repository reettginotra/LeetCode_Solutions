#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *l, TreeNode *r)
        : val(x), left(l), right(r) {}
};

// LeetCode solution starts from here
class Solution {
public:
    unordered_map<long long, int> mp;

    int dfs(TreeNode* node, long long sum, int target) {
        if (!node) return 0;

        sum += node->val;

        int ans = mp[sum - target];

        mp[sum]++;

        ans += dfs(node->left, sum, target);
        ans += dfs(node->right, sum, target);

        mp[sum]--;

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0, targetSum);
    }
};