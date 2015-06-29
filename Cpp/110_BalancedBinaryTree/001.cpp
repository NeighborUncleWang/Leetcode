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
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root) >= 0;
    }
private:
    int isBalancedHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = isBalancedHelper(root->left);
        int right = isBalancedHelper(root->right);
        if (left == -1 || right == -1) {
            return -1;
        }
        if (abs(left - right) >= 2) {
            return -1;
        }
        return max(left, right) + 1;
    }
};
