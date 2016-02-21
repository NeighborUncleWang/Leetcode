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
        TreeNode* predecessor = nullptr;
        helper(root, predecessor);
    }
private:
    void helper(TreeNode* current, TreeNode*& predecessor) {
        if (current == nullptr) return;
        if (predecessor != nullptr) {
            predecessor->right = current;
            predecessor->left = nullptr;
        }
        predecessor = current;
        //这里要把current->right记录下来
        //因为后面helper(current->left, prdecessor)
        //过程中会修改prdecessor->right(也就是current->right)
        //导致helper(current->right, predecessor)会出错
        auto right = current->right;
        helper(current->left, predecessor);
        helper(right, predecessor);
    }
};