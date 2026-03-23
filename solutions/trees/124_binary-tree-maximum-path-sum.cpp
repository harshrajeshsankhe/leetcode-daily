```cpp
/*
Problem: Binary Tree Maximum Path Sum
Problem Number: 124
Difficulty: Hard
Topic: trees
Date: 2026-03-23

Approach:
Use DFS to compute, for each node, the maximum "gain" from a path starting at that node and extending downward to one child (or stopping).
While returning gains upward, update a global answer with the best path that passes through the current node using both left and right gains (ignoring negative gains).
This ensures all possible path shapes are considered while keeping the recursion state minimal.

Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack, h = tree height
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
    int maxPathSum(TreeNode* root) {
        long long best = LLONG_MIN;
        dfs(root, best);
        return (int)best;
    }

private:
    // Returns maximum gain starting at node and going downward (choose at most one child).
    long long dfs(TreeNode* node, long long& best) {
        if (!node) return 0;

        long long leftGain  = dfs(node->left, best);
        long long rightGain = dfs(node->right, best);

        // We can drop negative contributions since any path can start/end anywhere.
        leftGain = max(0LL, leftGain);
        rightGain = max(0LL, rightGain);

        // Best path that uses this node as the highest (turning) point.
        long long through = (long long)node->val + leftGain + rightGain;
        best = max(best, through);

        // Gain to parent: node + best one-side extension.
        return (long long)node->val + max(leftGain, rightGain);
    }
};
```