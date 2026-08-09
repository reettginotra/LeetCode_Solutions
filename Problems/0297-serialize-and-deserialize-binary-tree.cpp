#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    void dfs(TreeNode* node, string& res) {
        if (!node) {
            res += "null,";
            return;
        }

        res += to_string(node->val) + ",";
        dfs(node->left, res);
        dfs(node->right, res);
    }

    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& index) {
        if (vals[index] == "null") {
            index++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[index++]));

        node->left = dfsDeserialize(vals, index);
        node->right = dfsDeserialize(vals, index);

        return node;
    }

    TreeNode* deserialize(string data) {
        vector<string> vals;
        string temp;

        stringstream ss(data);
        while (getline(ss, temp, ','))
            vals.push_back(temp);

        int index = 0;
        return dfsDeserialize(vals, index);
    }
};