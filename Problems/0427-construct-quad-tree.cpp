#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// LeetCode solution starts from here
class Solution {
public:
    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        bool same = true;
        int v = grid[x][y];

        for (int i = x; i < x + len && same; i++) {
            for (int j = y; j < y + len; j++) {
                if (grid[i][j] != v) {
                    same = false;
                    break;
                }
            }
        }

        if (same)
            return new Node(v, true);

        int h = len >> 1;

        return new Node(
            true,
            false,
            build(grid, x, y, h),
            build(grid, x, y + h, h),
            build(grid, x + h, y, h),
            build(grid, x + h, y + h, h)
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};