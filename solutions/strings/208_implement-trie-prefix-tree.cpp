```cpp
/*
Problem: Implement Trie (Prefix Tree)
Problem Number: 208
Difficulty: Medium
Topic: strings
Date: 2026-03-24

Approach:
Use a Trie where each node stores indices to 26 children (for 'a'..'z') and a flag indicating whether a word ends at that node.
Insert walks/creates nodes along the characters; search walks nodes and checks the end flag; startsWith walks nodes without requiring the end flag.
Store all nodes in a vector (node pool) and refer to children by integer indices for cache-friendly, allocation-light performance.

Time Complexity: O(L) per operation, where L is the length of the input string.
Space Complexity: O(total characters inserted) nodes, each with 26 child links and an end flag.
*/

class Solution {
public:
    struct Node {
        int next[26];
        bool end;
        Node() : end(false) { std::fill(next, next + 26, -1); }
    };

    std::vector<Node> trie; // node pool; trie[0] is root

    Solution() {
        trie.reserve(1 << 16);
        trie.emplace_back(); // root
    }

    void insert(const std::string& word) {
        int cur = 0;
        for (char c : word) {
            int id = c - 'a';
            if (trie[cur].next[id] == -1) {
                trie[cur].next[id] = (int)trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].next[id];
        }
        trie[cur].end = true;
    }

    bool search(const std::string& word) {
        int cur = 0;
        for (char c : word) {
            int id = c - 'a';
            cur = trie[cur].next[id];
            if (cur == -1) return false;
        }
        return trie[cur].end;
    }

    bool startsWith(const std::string& prefix) {
        int cur = 0;
        for (char c : prefix) {
            int id = c - 'a';
            cur = trie[cur].next[id];
            if (cur == -1) return false;
        }
        return true;
    }
};
```