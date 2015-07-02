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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->right = invertTree(root->right);
        root->left = invertTree(root->left);
        auto right = root->right;
        root->right = root->left;
        root->left = right;
        return root;
    }
};
