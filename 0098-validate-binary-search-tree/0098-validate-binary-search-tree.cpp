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
    bool checkBST(TreeNode* root, long long minValue, long long maxValue) {

        // Empty tree is valid
        if (root == nullptr)
            return true;

        // Current value must be strictly inside the allowed range
        if (root->val <= minValue || root->val >= maxValue)
            return false;

        // Left subtree: values must be smaller than root->val
        bool leftValid = checkBST(root->left, minValue, root->val);

        // Right subtree: values must be greater than root->val
        bool rightValid = checkBST(root->right, root->val, maxValue);

        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};