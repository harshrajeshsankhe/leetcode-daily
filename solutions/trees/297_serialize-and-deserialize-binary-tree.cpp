```cpp
/*
Problem: Serialize and Deserialize Binary Tree
Problem Number: 297
Difficulty: Hard
Topic: trees
Date: 2026-04-05

Approach:
Use preorder DFS serialization with a sentinel (#) for null pointers and commas as separators. For deserialization, parse tokens sequentially and rebuild the tree recursively in the same preorder order, consuming one token per node/null. This guarantees a unique reconstruction while keeping the format compact and linear.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    static constexpr const char* NIL = "#";

    void serializeDfs(TreeNode* node, std::string& out) {
        if (!node) {
            out += NIL;
            out.push_back(',');
            return;
        }
        out += std::to_string(node->val);
        out.push_back(',');
        serializeDfs(node->left, out);
        serializeDfs(node->right, out);
    }

    // Reads next token [start, end) and advances i to character after delimiter (or end).
    std::string_view nextToken(const std::string& s, size_t& i) {
        size_t start = i;
        while (i < s.size() && s[i] != ',') ++i;
        size_t end = i;
        if (i < s.size() && s[i] == ',') ++i; // skip comma
        return std::string_view(s.data() + start, end - start);
    }

    TreeNode* deserializeDfs(const std::string& data, size_t& i) {
        if (i >= data.size()) return nullptr; // defensive
        std::string_view tok = nextToken(data, i);
        if (tok == NIL) return nullptr;

        int val = 0;
        // stoi for string_view (manual parse; handles optional leading '-')
        bool neg = false;
        size_t p = 0;
        if (!tok.empty() && tok[0] == '-') { neg = true; p = 1; }
        for (; p < tok.size(); ++p) val = val * 10 + (tok[p] - '0');
        if (neg) val = -val;

        TreeNode* node = new TreeNode(val);
        node->left = deserializeDfs(data, i);
        node->right = deserializeDfs(data, i);
        return node;
    }

public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string out;
        out.reserve(64); // small default; grows as needed
        serializeDfs(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        size_t i = 0;
        return deserializeDfs(data, i);
    }
};
```