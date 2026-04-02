```cpp
/*
Problem: Same Tree
Problem Number: 100
Difficulty: Easy
Topic: trees
Date: 2026-04-02

Approach:
Traverse both trees simultaneously using recursion. At each pair of nodes, ensure they are both null (equal), or both non-null with the same value, and then recursively verify their left and right subtrees. If any mismatch is found, return false immediately; otherwise, the trees are identical.

Time Complexity: O(n)
Space Complexity: O(h)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are null => identical at this subtree.
        if (!p && !q) return true;
        // One is null => structure differs.
        if (!p || !q) return false;
        // Values differ => not same.
        if (p->val != q->val) return false;

        // Recurse on children.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```