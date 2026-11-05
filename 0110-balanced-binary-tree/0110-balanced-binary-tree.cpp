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
    int height(TreeNode* root) {
        // Empty tree has height 0
        if (root == nullptr)
            return 0;

        // Get left subtree height
        int leftHeight = height(root->left);

        // If left subtree is unbalanced
        if (leftHeight == -1)
            return -1;

        // Get right subtree height
        int rightHeight = height(root->right);

        // If right subtree is unbalanced
        if (rightHeight == -1)
            return -1;

        // Check balance condition
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};