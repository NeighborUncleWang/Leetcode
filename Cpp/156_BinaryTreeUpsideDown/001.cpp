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
        return dfsBottomUp(root, nullptr);
    }
private:
    TreeNode* dfsBottomUp(TreeNode* current, TreeNode* parent) {
        if (current == nullptr) {
            return parent;
        }
        TreeNode* newRoot = dfsBottomUp(current->left, current);
        current->left = parent == nullptr ? nullptr : parent->right;
        current->right = parent;
        return newRoot;
    }
};