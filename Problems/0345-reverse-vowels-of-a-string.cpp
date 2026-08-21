#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int i = 0, j = s.size() - 1;

        while (i < j) {
            while (i < j && vowels.find(s[i]) == string::npos)
                i++;

            while (i < j && vowels.find(s[j]) == string::npos)
                j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};