```cpp
/*
Problem: Symmetric Tree
Problem Number: 101
Difficulty: Easy
Topic: trees
Date: 2026-04-02

Approach:
Use a recursive mirror-check: two subtrees are symmetric if their root values match and the left subtree of one is a mirror of the right subtree of the other (and vice versa).
Start by comparing the root with itself via a helper that takes two nodes and validates mirrored structure and values.
This DFS directly enforces symmetry constraints at each pair of mirrored positions.

Time Complexity: O(n)
Space Complexity: O(h)  (recursion stack; worst-case O(n) for skewed tree)
*/

class Solution {
private:
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        // Mirror: left with right, right with left
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
```