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
private:
    int dfs(TreeNode* cur, TreeNode* parent) {
        if (!cur) {
            return 0;
        } else if (cur->left == nullptr && cur->right == nullptr && parent && cur == parent->left) {
            return cur->val;
        }
        return dfs(cur->left, cur) + dfs(cur->right, cur);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, nullptr);
    }
};