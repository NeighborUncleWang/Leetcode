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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int max_count = 0, count = 0, mode_count = 0;
        TreeNode* pre = nullptr;
        helper(pre, root, max_count, count, res, false);
        count = 0;
        helper(pre, root, max_count, count, res, true);
        return res;
    }
private:
    void helper(TreeNode*& pre, TreeNode* current, int& max_count, int& count,
    vector<int>& res, bool flag) {
        if (current == nullptr) return;
        helper(pre, current->left, max_count, count, res, flag);
        if (pre && pre->val != current->val) {
            count = 0;
        }
        ++count;
        if (count > max_count) {
            max_count = count;
        } else if (flag && count == max_count) {
            res.push_back(current->val);
        }
        pre = current;
        helper(pre, current->right, max_count, count, res, flag);
    }
};