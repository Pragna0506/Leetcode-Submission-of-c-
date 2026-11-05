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
    TreeNode* searchBST(TreeNode* root, int val) {

        // Tree is empty or value not found
        if (root == nullptr)
            return nullptr;

        // Found the node
        if (root->val == val)
            return root;

        // Search in left subtree
        if (val < root->val)
            return searchBST(root->left, val);

        // Search in right subtree
        return searchBST(root->right, val);
    }
};