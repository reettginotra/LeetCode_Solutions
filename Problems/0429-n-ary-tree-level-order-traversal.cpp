#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


// LeetCode solution starts from here
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            ans.emplace_back();

            while (sz--) {
                Node* cur = q.front();
                q.pop();

                ans.back().push_back(cur->val);

                for (Node* child : cur->children)
                    q.push(child);
            }
        }

        return ans;
    }
};