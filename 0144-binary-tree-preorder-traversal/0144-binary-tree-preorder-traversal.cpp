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
    void preorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;

        // 1. Visit Root
        result.push_back(root->val);

        // 2. Visit Left
        preorder(root->left, result);

        // 3. Visit Right
        preorder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        preorder(root, result);

        return result;
    }
};