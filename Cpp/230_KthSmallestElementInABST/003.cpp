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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        helper(root, k, result);
        return result;
    }
private:
    void helper(TreeNode* current, int& k, int& result) {
        if (current == nullptr) {
            return;
        }
        helper(current->left, k, result);
        if (--k == 0) {
            result = current->val;
            return;
        }
        helper(current->right, k, result);
    }
};