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
    bool isValidBST(TreeNode* root) {
        TreeNode *predecessor = nullptr;
        return isValidBSTHelper(root, predecessor);
    }
private:
    bool isValidBSTHelper(TreeNode *node, TreeNode*& predecessor) {
        if (node == nullptr) {
            return true;
        }
        bool checkLeft = isValidBSTHelper(node->left, predecessor);
        if (predecessor != nullptr && predecessor->val >= node->val) {
            return false;
        }
        predecessor = node;
        return checkLeft && isValidBSTHelper(node->right, predecessor);
    }
};
