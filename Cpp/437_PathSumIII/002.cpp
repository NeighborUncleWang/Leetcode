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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int helper(TreeNode* current, int pre_sum, int target) {
        if (current == nullptr) return 0;
        int sum = pre_sum + current->val;
        return (sum == target ? 1 : 0) + helper(current->left, sum, target) + helper(current->right, sum, target);
    }
};