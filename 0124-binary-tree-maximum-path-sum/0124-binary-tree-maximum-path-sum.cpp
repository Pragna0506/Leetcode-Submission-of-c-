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

    int maxPath = INT_MIN;

    int findMaxGain(TreeNode* root) {

        if (root == nullptr)
            return 0;

        // Maximum contribution from left subtree
        int leftGain = max(0, findMaxGain(root->left));

        // Maximum contribution from right subtree
        int rightGain = max(0, findMaxGain(root->right));

        // Best path passing through current node
        int currentPath = leftGain + root->val + rightGain;

        // Update global maximum
        maxPath = max(maxPath, currentPath);

        // Return the best single-side path to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {

        findMaxGain(root);

        return maxPath;
    }
};