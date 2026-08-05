#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<unordered_set<char>> rows, cols, boxes;

    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int box = (i / 3) * 3 + j / 3;

                    for (char num = '1'; num <= '9'; num++) {
                        if (!rows[i].count(num) &&
                            !cols[j].count(num) &&
                            !boxes[box].count(num)) {

                            board[i][j] = num;
                            rows[i].insert(num);
                            cols[j].insert(num);
                            boxes[box].insert(num);

                            if (backtrack(board))
                                return true;

                            board[i][j] = '.';
                            rows[i].erase(num);
                            cols[j].erase(num);
                            boxes[box].erase(num);
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        rows.assign(9, unordered_set<char>());
        cols.assign(9, unordered_set<char>());
        boxes.assign(9, unordered_set<char>());

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[(i / 3) * 3 + j / 3].insert(board[i][j]);
                }
            }
        }

        backtrack(board);
    }
};