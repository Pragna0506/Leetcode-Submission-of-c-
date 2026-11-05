/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {

        if (root == nullptr)
            return nullptr;

        Node* leftmost = root;

        // Continue level by level
        while (leftmost->left != nullptr) {

            Node* current = leftmost;

            while (current != nullptr) {

                // Connect left child to right child
                current->left->next = current->right;

                // Connect right child to next parent's left child
                if (current->next != nullptr) {
                    current->right->next = current->next->left;
                }

                current = current->next;
            }

            // Move to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};
