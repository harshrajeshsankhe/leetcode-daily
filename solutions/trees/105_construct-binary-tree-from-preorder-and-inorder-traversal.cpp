```cpp
/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal
Problem Number: 105
Difficulty: Medium
Topic: trees
Date: 2026-03-15

Approach:
Use preorder to pick the next root in O(1) by advancing an index, and use a hash map from node value to its position in inorder to split the inorder segment into left and right subtrees. Recursively build the tree by constructing the left subtree from the left inorder segment, then the right subtree from the right segment. This avoids repeated searches and ensures each node is processed once.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int n = (int)preorder.size();
        if (n == 0) return nullptr;

        // Map value -> index in inorder for O(1) splits.
        unordered_map<int, int> pos;
        pos.reserve(n * 2);
        pos.max_load_factor(0.7f);
        for (int i = 0; i < n; ++i) pos[inorder[i]] = i;

        int preIdx = 0; // Current root index in preorder.

        // Build subtree spanning inorder[l..r] inclusive.
        function<TreeNode*(int, int)> build = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;

            int rootVal = preorder[preIdx++];
            TreeNode* root = new TreeNode(rootVal);

            int mid = pos[rootVal]; // Root splits inorder into left/right.
            root->left = build(l, mid - 1);
            root->right = build(mid + 1, r);
            return root;
        };

        return build(0, n - 1);
    }
};
```