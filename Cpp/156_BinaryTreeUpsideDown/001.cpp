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
        auto node = dfsBottomUp(root, nullptr);
        return node;
    }
private:
    TreeNode* dfsBottomUp(TreeNode* node, TreeNode* parent) {
        if (node == nullptr) {
            return parent;
        }
        auto root = dfsBottomUp(node->left, node);
        node->left = parent == nullptr ? nullptr : parent->right;
        node->right = parent;
        return root;
    }
};
