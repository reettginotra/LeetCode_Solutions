#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;
};

class Solution {
public:
    vector<string> res;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (!node->children.count(ch))
            return;

        TrieNode* nxt = node->children[ch];

        if (!nxt->word.empty()) {
            res.push_back(nxt->word);
            nxt->word.clear();
        }

        board[r][c] = '#';

        static int dr[] = {1, -1, 0, 0};
        static int dc[] = {0, 0, 1, -1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size() &&
                board[nr][nc] != '#') {
                dfs(board, nr, nc, nxt);
            }
        }

        board[r][c] = ch;

        if (nxt->children.empty()) {
            delete nxt;
            node->children.erase(ch);
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) {
            TrieNode* node = root;

            for (char ch : word) {
                if (!node->children.count(ch))
                    node->children[ch] = new TrieNode();

                node = node->children[ch];
            }

            node->word = word;
        }

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root);

        return res;
    }
};