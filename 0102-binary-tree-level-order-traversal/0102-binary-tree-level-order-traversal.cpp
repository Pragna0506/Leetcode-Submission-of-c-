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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            // Process all nodes of the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                currentLevel.push_back(current->val);

                // Add left child
                if (current->left != nullptr)
                    q.push(current->left);

                // Add right child
                if (current->right != nullptr)
                    q.push(current->right);
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};