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
        auto current = root;
        TreeNode* parent = nullptr;
        TreeNode* parentRight = nullptr;
        while (current != nullptr) {
            auto left = current->left;
            current->left = parentRight;
            parentRight = current->right;
            current->right = parent;
            parent = current;
            current = left;
        }
        return parent;
    }
};