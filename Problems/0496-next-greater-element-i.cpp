#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nxt;
        stack<int> st;

        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                nxt[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        while (!st.empty()) {
            nxt[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        ans.reserve(nums1.size());

        for (int x : nums1)
            ans.push_back(nxt[x]);

        return ans;
    }
};