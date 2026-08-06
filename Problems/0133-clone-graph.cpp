#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* node) {
        if (visited.count(node))
            return visited[node];

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for (Node* neighbor : node->neighbors)
            clone->neighbors.push_back(dfs(neighbor));

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        return dfs(node);
    }
};