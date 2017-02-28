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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* pre = nullptr;
        dfs(pre, root, res);
        return res;
    }
private:
    void dfs(TreeNode*& pre, TreeNode* cur, int& res) {
        if (cur == nullptr) return;
        dfs(pre, cur->left, res);
        if (pre) {
            res = min(res, cur->val - pre->val);
        }
        pre = cur;
        dfs(pre, cur->right, res);
    }
};