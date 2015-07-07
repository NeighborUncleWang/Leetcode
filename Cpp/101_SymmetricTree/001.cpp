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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        if (leftNode == nullptr || rightNode == nullptr) {
            return false;
        }
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left);
    }
};
