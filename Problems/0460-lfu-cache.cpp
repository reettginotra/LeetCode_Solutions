#include <bits/stdc++.h>
using namespace std;

// LeetCode solution starts from here
class LFUCache {
    struct Node {
        int key, val, freq;
        Node *prev, *next;

        Node(int k = 0, int v = 0)
            : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct DLinkedList {
        Node *head, *tail;
        int size;

        DLinkedList() {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void add(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* pop() {
            if (!size)
                return nullptr;

            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    int cap, minFreq;
    unordered_map<int, Node*> nodes;
    unordered_map<int, DLinkedList*> freqs;

    void update(Node* node) {
        int f = node->freq;
        DLinkedList* list = freqs[f];

        list->remove(node);

        if (f == minFreq && list->size == 0)
            minFreq++;

        node->freq++;

        if (!freqs.count(node->freq))
            freqs[node->freq] = new DLinkedList();

        freqs[node->freq]->add(node);
    }

public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) {
        if (!nodes.count(key))
            return -1;

        Node* node = nodes[key];
        update(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (nodes.count(key)) {
            Node* node = nodes[key];
            node->val = value;
            update(node);
            return;
        }

        if (nodes.size() == cap) {
            Node* node = freqs[minFreq]->pop();
            nodes.erase(node->key);
            delete node;
        }

        Node* node = new Node(key, value);
        nodes[key] = node;

        if (!freqs.count(1))
            freqs[1] = new DLinkedList();

        freqs[1]->add(node);
        minFreq = 1;
    }
};