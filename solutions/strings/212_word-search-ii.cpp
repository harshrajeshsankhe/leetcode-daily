```cpp
/*
Problem: Word Search II
Problem Number: 212
Difficulty: Hard
Topic: strings
Date: 2026-04-02

Approach:
Build a Trie from all words, storing the word index at terminal nodes. Run DFS from each board cell, walking the Trie in lockstep;
prune immediately when the next character is absent, and mark visited cells in-place. When a terminal Trie node is reached, record
the word and clear the terminal marker to avoid duplicates; also prune empty Trie branches on backtracking to speed up future searches.

Time Complexity: O(M*N*4^L) in the worst case, but heavily pruned by the Trie (typically much faster); building the Trie is O(total letters).
Space Complexity: O(total letters) for the Trie + O(L) recursion stack.
*/

class Solution {
    struct Node {
        int next[26];
        int wordId; // index into words, -1 if none
        int childCount;
        Node() : wordId(-1), childCount(0) {
            std::fill(next, next + 26, -1);
        }
    };

    std::vector<Node> trie;
    std::vector<std::string> *wptr;
    std::vector<std::string> ans;
    int m = 0, n = 0;

    inline int idx(char c) { return c - 'a'; }

    void addWord(const std::string &s, int id) {
        int cur = 0;
        for (char ch : s) {
            int c = idx(ch);
            if (trie[cur].next[c] == -1) {
                trie[cur].next[c] = (int)trie.size();
                trie.emplace_back();
                trie[cur].childCount++;
            }
            cur = trie[cur].next[c];
        }
        trie[cur].wordId = id;
    }

    // Returns true if the child node became useless (no children and no word), allowing parent to prune that edge.
    bool dfs(std::vector<std::vector<char>> &board, int r, int c, int nodeIdx) {
        char ch = board[r][c];
        if (ch == '#') return false;

        int to = trie[nodeIdx].next[idx(ch)];
        if (to == -1) return false;

        Node &node = trie[to];

        // Found a word.
        if (node.wordId != -1) {
            ans.push_back((*wptr)[node.wordId]);
            node.wordId = -1; // de-duplicate: never report same word twice
        }

        board[r][c] = '#';

        // Explore neighbors.
        if (r > 0) dfs(board, r - 1, c, to);
        if (r + 1 < m) dfs(board, r + 1, c, to);
        if (c > 0) dfs(board, r, c - 1, to);
        if (c + 1 < n) dfs(board, r, c + 1, to);

        board[r][c] = ch;

        // Prune: if this node is now dead, tell caller to remove edge.
        if (node.wordId != -1) return false;
        if (node.childCount != 0) return false;
        return true;
    }

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
        ans.clear();
        wptr = &words;
        m = (int)board.size();
        if (m == 0) return ans;
        n = (int)board[0].size();
        if (n == 0 || words.empty()) return ans;

        trie.clear();
        trie.reserve(1);
        trie.emplace_back(); // root

        // Insert all words into Trie.
        for (int i = 0; i < (int)words.size(); ++i) {
            if (!words[i].empty()) addWord(words[i], i);
        }

        // DFS from each cell; dynamic pruning of Trie edges for speed.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = board[i][j];
                if (ch < 'a' || ch > 'z') continue;
                int c = idx(ch);
                int child = trie[0].next[c];
                if (child == -1) continue;

                // If dfs returns true, the child became dead and we can prune root edge.
                if (dfs(board, i, j, 0)) {
                    trie[0].next[c] = -1;
                    trie[0].childCount--;
                }
            }
        }

        return ans;
    }
};
```