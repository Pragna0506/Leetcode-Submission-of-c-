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

    int countGoodNodes(TreeNode* root, int maxSoFar) {

        if (root == nullptr)
            return 0;

        int count = 0;

        // Check if current node is good
        if (root->val >= maxSoFar)
            count = 1;

        // Update maximum value seen so far
        maxSoFar = max(maxSoFar, root->val);

        // Search left and right subtrees
        count += countGoodNodes(root->left, maxSoFar);
        count += countGoodNodes(root->right, maxSoFar);

        return count;
    }

    int goodNodes(TreeNode* root) {

        return countGoodNodes(root, root->val);
    }
};