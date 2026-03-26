```cpp
/*
Problem: Binary Tree Inorder Traversal
Problem Number: 94
Difficulty: Easy
Topic: trees
Date: 2026-03-26

Approach:
Use Morris inorder traversal to achieve O(1) extra space by temporarily threading the tree.
For each node, if it has no left child, record it and move right; otherwise, find its inorder predecessor.
Create a temporary link from the predecessor to the current node to return after finishing the left subtree, then remove it when revisiting.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary (excluding output)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;

        while (cur) {
            if (!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                // Find inorder predecessor of cur in its left subtree.
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;

                if (!pred->right) {
                    // Thread the tree: link predecessor back to current node.
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    // Left subtree done; remove thread, visit current, and go right.
                    pred->right = nullptr;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
```