#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// LeetCode solution starts from here
class Solution {
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int ans = head->val;
        ListNode* node = head->next;
        int i = 2;

        while (node) {
            if (rand() % i == 0)
                ans = node->val;

            node = node->next;
            i++;
        }

        return ans;
    }
};
