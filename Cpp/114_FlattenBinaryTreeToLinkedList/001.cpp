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
    void flatten(TreeNode* root) {
        TreeNode *predecessor = nullptr;
        flattenHelper(root, predecessor);
    }
private:
    void flattenHelper(TreeNode *node, TreeNode*& predecessor) {//the second parameter predecessor must be passed by mutable reference not passed by value
        if (node == nullptr) {
            return;
        }
        TreeNode *right = node->right;
        if (predecessor != nullptr) {
            predecessor->left = nullptr;
            predecessor->right = node;
        }
        predecessor = node;
        flattenHelper(node->left, predecessor);
        flattenHelper(right, predecessor);
    } 
};
