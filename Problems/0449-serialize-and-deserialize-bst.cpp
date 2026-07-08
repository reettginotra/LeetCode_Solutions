#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// LeetCode solution starts from here
class Codec {
public:
    void preorder(TreeNode* root, string& s) {
        if (!root) return;

        s += to_string(root->val);
        s += ' ';

        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode* build(vector<int>& v, int& i, int low, int high) {
        if (i == v.size())
            return nullptr;

        int x = v[i];

        if (x < low || x > high)
            return nullptr;

        TreeNode* node = new TreeNode(x);
        i++;

        node->left = build(v, i, low, x);
        node->right = build(v, i, x, high);

        return node;
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        vector<int> v;
        int x = 0;

        for (int i = 0; i < data.size();) {
            x = 0;

            while (i < data.size() && data[i] != ' ') {
                x = x * 10 + (data[i] - '0');
                i++;
            }

            v.push_back(x);
            i++;
        }

        int idx = 0;
        return build(v, idx, INT_MIN, INT_MAX);
    }
};