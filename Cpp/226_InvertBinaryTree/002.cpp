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
        invertTreeHelper(root);
        return root;
    }
private:
    void invertTreeHelper(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        auto left = node->left;
        node->left = node->right;
        node->right = left;
        invertTreeHelper(node->left);
        invertTreeHelper(node->right);
    }
};
