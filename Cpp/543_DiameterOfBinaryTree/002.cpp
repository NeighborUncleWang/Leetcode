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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    int helper(TreeNode* cur, int& res) {
        if (cur == nullptr) return 0;
        auto left = helper(cur->left, res);
        auto right = helper(cur->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};