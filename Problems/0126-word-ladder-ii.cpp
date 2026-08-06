#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord))
            return {};

        unordered_map<string, vector<string>> parents;
        unordered_set<string> level = {beginWord};
        bool found = false;

        while (!level.empty() && !found) {
            unordered_map<string, vector<string>> nextLevel;

            for (auto &word : level)
                wordSet.erase(word);

            for (auto &word : level) {
                string cur = word;

                for (int i = 0; i < cur.size(); i++) {
                    char old = cur[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        cur[i] = c;

                        if (wordSet.count(cur)) {
                            nextLevel[cur].push_back(word);

                            if (cur == endWord)
                                found = true;
                        }
                    }

                    cur[i] = old;
                }
            }

            level.clear();

            for (auto &it : nextLevel) {
                level.insert(it.first);
                parents[it.first].insert(parents[it.first].end(),
                                         it.second.begin(), it.second.end());
            }
        }

        vector<vector<string>> ans;
        vector<string> path = {endWord};

        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                return;
            }

            for (auto &p : parents[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        if (found)
            dfs(endWord);

        return ans;
    }
};