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
        return dfsDepth(root) != -1;
    }
private:
    int dfsDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftDepth = dfsDepth(node->left);
        int rightDepth = dfsDepth(node->right);
        if (leftDepth >= 0 && rightDepth >= 0 
        && abs(leftDepth - rightDepth) <= 1) {
            return max(leftDepth, rightDepth) + 1;
        } else {
            return -1;
        }
    }
};