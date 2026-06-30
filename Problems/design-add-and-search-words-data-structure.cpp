#include <iostream>
#include <string>

using namespace std;
//leetcode sol starts from here
class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string &word, int index, TrieNode* node) {
        if (!node) return false;

        if (index == word.size())
            return node->isEnd;

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && dfs(word, index + 1, node->child[i]))
                    return true;
            }
            return false;
        }

        return dfs(word, index + 1, node->child[word[index] - 'a']);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';
            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

int main() {
    WordDictionary obj;

    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");

    cout << boolalpha;
    cout << obj.search("pad") << endl;
    cout << obj.search("bad") << endl;
    cout << obj.search(".ad") << endl;
    cout << obj.search("b..") << endl;

    return 0;
}