#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// LeetCode solution starts from hereclass Solution 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        auto slow = &dummy;
        auto fast = &dummy;
        while (n > 0) {
            fast = fast->next;
            --n;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        auto node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;

        return dummy.next;
    }
};