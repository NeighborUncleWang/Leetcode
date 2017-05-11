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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
private:
    pair<int, int> dfs(TreeNode* cur, int& res) {
        if (cur == nullptr) return pair<int, int>{0, 0};
        int increase = 1, decrease = 1;
        if (cur->left) {
            auto left = dfs(cur->left, res);
            if (cur->val + 1 == cur->left->val) {
                increase = left.first + 1;
            } else if (cur->val - 1 == cur->left->val) {
                decrease = left.second + 1;
            }
        }
        if (cur->right) {
            auto right = dfs(cur->right, res);
            if (cur->val + 1 == cur->right->val) {
                increase = max(increase, right.first + 1);
            } else if (cur->val - 1 == cur->right->val) {
                decrease = max(decrease, right.second + 1);
            }
        }
        res = max(res, increase + decrease - 1);
        return make_pair(increase, decrease);
    }
};