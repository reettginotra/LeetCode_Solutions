from typing import List
from collections import defaultdict

#leetcode sol starts from here
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return []

        parents = defaultdict(list)
        level = {beginWord}
        found = False

        while level and not found:
            nextLevel = defaultdict(list)

            for word in level:
                wordSet.discard(word)

            for word in level:
                for i in range(len(word)):
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        newWord = word[:i] + c + word[i + 1:]

                        if newWord in wordSet:
                            nextLevel[newWord].append(word)
                            if newWord == endWord:
                                found = True

            level = set(nextLevel.keys())

            for child in nextLevel:
                parents[child].extend(nextLevel[child])

        res = []

        def dfs(word, path):
            if word == beginWord:
                res.append(path[::-1])
                return

            for p in parents[word]:
                dfs(p, path + [p])

        if found:
            dfs(endWord, [endWord])

        return res