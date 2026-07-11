#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
    unordered_map<string, int> memo;

    string removeBalls(string board) {
        for (int i = 0, j; i < board.size(); i = j) {
            j = i + 1;
            while (j < board.size() && board[j] == board[i])
                j++;
            if (j - i >= 3)
                return removeBalls(board.substr(0, i) + board.substr(j));
        }
        return board;
    }

    int dfs(string board, vector<int>& hand) {
        board = removeBalls(board);

        if (board.empty())
            return 0;

        string key = board + "#";
        for (int x : hand)
            key += char(x + '0');

        auto it = memo.find(key);
        if (it != memo.end())
            return it->second;

        int ans = INT_MAX;

        for (int i = 0; i <= board.size(); i++) {
            for (int c = 0; c < 5; c++) {
                if (hand[c] == 0)
                    continue;

                char ch = "RYBGW"[c];

                if (i > 0 && board[i - 1] == ch)
                    continue;

                if ((i < board.size() && board[i] == ch) ||
                    (i > 0 && i < board.size() && board[i - 1] == board[i] && board[i] != ch)) {

                    hand[c]--;

                    string nxt = board.substr(0, i) + ch + board.substr(i);

                    int res = dfs(nxt, hand);

                    if (res != -1)
                        ans = min(ans, res + 1);

                    hand[c]++;
                }
            }
        }

        memo[key] = (ans == INT_MAX ? -1 : ans);
        return memo[key];
    }

public:
    int findMinStep(string board, string hand) {
        vector<int> cnt(5, 0);

        for (char c : hand) {
            if (c == 'R')
                cnt[0]++;
            else if (c == 'Y')
                cnt[1]++;
            else if (c == 'B')
                cnt[2]++;
            else if (c == 'G')
                cnt[3]++;
            else
                cnt[4]++;
        }

        return dfs(board, cnt);
    }
};