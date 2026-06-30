#include <iostream>
#include <vector>
#include <string>

using namespace std;
//leetcode sol starts from here 

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> cnt(3, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] && cnt[1] && cnt[2]) {
                ans += n - right;
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};