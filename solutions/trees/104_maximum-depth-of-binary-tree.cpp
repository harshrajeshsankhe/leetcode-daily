/*
Problem: Maximum Depth of Binary Tree
Problem Number: 104
Difficulty: Easy
Topic: trees
Date: 2026-04-05

Approach:
Use depth-first search (recursion): the maximum depth of a node is 1 plus the maximum of the depths of its left and right subtrees. The base case is a null pointer, which has depth 0. This directly matches the definition of tree depth and visits each node once.

Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack, where h is the tree height
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};