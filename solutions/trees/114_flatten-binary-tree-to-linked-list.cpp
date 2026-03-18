```cpp
/*
Problem: Flatten Binary Tree to Linked List
Problem Number: 114
Difficulty: Medium
Topic: trees
Date: 2026-03-18

Approach:
Use an in-place iterative method (Morris-like) to rewire pointers without extra memory. For each node, if it has a left subtree, find the rightmost node in that left subtree (predecessor), attach the current node's right subtree to predecessor->right, then move the left subtree to the right and nullify left. Advance along the right pointers until the tree is flattened into a preorder-linked list.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                // Find the rightmost node in the left subtree (predecessor).
                TreeNode* pred = cur->left;
                while (pred->right) pred = pred->right;

                // Splice: predecessor's right points to current's right subtree.
                pred->right = cur->right;

                // Move left subtree to the right and clear left.
                cur->right = cur->left;
                cur->left = nullptr;
            }
            // Continue along the (possibly updated) right chain.
            cur = cur->right;
        }
    }
};
```