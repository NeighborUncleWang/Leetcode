/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* predecessor = nullptr;//trace the predecessor for in order traversal
        TreeNode* firstElement = nullptr;
        TreeNode* secondElement = nullptr;
        auto current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                if (predecessor && predecessor->val > current->val) {
                    if (firstElement == nullptr) {
                        firstElement = predecessor;
                    }
                    secondElement = current;
                }
                predecessor = current;
                current = current->right;
            } else {
                auto temp = current->left;
                while (temp->right && temp->right != current) {
                    temp = temp->right;
                }
                if (temp->right == nullptr) {
                    temp->right = current;
                    current = current->left;
                } else {
                    if (predecessor && predecessor->val > current->val) {
                        if (firstElement == nullptr) {
                            firstElement = predecessor;
                        }
                        secondElement = current;
                    }
                    predecessor = current;
                    current = current->right;
                    temp->right = nullptr;
                }
            }
        }
        swap(firstElement->val, secondElement->val);
    }
};