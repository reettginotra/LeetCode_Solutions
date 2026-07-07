#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {
        val = 0;
        prev = next = child = nullptr;
    }

    Node(int _val) {
        val = _val;
        prev = next = child = nullptr;
    }
};

// LeetCode solution starts from here
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        stack<Node*> st;
        st.push(head);

        Node* prev = nullptr;

        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();

            if (prev) {
                prev->next = cur;
                cur->prev = prev;
            }

            if (cur->next)
                st.push(cur->next);

            if (cur->child) {
                st.push(cur->child);
                cur->child = nullptr;
            }

            prev = cur;
        }

        head->prev = nullptr;
        return head;
    }
};