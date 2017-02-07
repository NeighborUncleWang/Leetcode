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
        if (root == nullptr) return vector<int>();
        vector<int> res;
        int count = 0, max_count = 0;
        TreeNode* pre = nullptr;
        helper(root, pre, count, max_count, res);
        if (count == max_count) {
            res.push_back(pre->val);
        } else if (count > max_count) {
            res = vector<int>{pre->val};
        }
        return res;
    }
private:
    void helper(TreeNode* current, TreeNode*& pre, int& count, int& max_count, vector<int>& res) {
        if (current == nullptr) return;
        helper(current->left, pre, count, max_count, res);
        if (pre && pre->val != current->val) {
            if (count == max_count) {
                res.push_back(pre->val);
            } else if (count > max_count) {
                res = vector<int>{pre->val};
                max_count = count;
            }
            count = 0;
        }
        pre = current;
        ++count;
        helper(current->right, pre, count, max_count, res);
    }
};