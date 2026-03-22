```cpp
/*
Problem: LRU Cache
Problem Number: 146
Difficulty: Medium
Topic: arrays
Date: 2026-03-22

Approach:
Use a hash map from key to a node pointer and a doubly linked list to maintain usage order.
The list stores items from most-recently-used (front) to least-recently-used (back); on get/put we move the accessed node to the front.
When capacity is exceeded, evict the node at the back and remove its key from the hash map.

Time Complexity: O(1) average per get/put
Space Complexity: O(capacity)
*/

class Solution {
public:
    // LeetCode expects class name: LRUCache
};

class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    std::unordered_map<int, Node*> mp;
    Node *head; // dummy head (MRU side)
    Node *tail; // dummy tail (LRU side)

    // Insert node right after head (most recently used position).
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove node from the linked list.
    void removeNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
        node->prev = node->next = nullptr;
    }

    // Move an existing node to the front.
    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    // Evict the least recently used real node (before tail).
    void evictLRU() {
        Node* lru = tail->prev;
        if (lru == head) return; // nothing to evict
        removeNode(lru);
        mp.erase(lru->key);
        delete lru;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mp.reserve((size_t)capacity * 2);
        mp.max_load_factor(0.7f);
    }

    ~LRUCache() {
        // Delete all nodes including sentinels.
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        Node* node = it->second;
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        auto it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            node->val = value;
            moveToFront(node);
            return;
        }

        if ((int)mp.size() == cap) evictLRU();

        Node* node = new Node(key, value);
        addToFront(node);
        mp[key] = node;
    }
};
```