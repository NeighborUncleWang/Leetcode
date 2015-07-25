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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        auto node = root;
        TreeNode* parent = nullptr;
        TreeNode* parentRight = nullptr;
        while (node != nullptr) {
            auto left = node->left;
            node->left = parentRight;
            parentRight = node->right;
            node->right = parent;
            parent = node;
            node = left;
        }
        return parent;
    }
};
