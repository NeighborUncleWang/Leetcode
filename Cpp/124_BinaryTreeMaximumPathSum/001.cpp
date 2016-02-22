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
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        maxPathDown(root, maxValue);
        return maxValue;
    }
private:
    int maxPathDown(TreeNode* current, int& maxValue) {
        if (current == nullptr) return 0;
        int leftSum = max(0, maxPathDown(current->left, maxValue));
        int rightSum = max(0, maxPathDown(current->right, maxValue));
        maxValue = max(maxValue, leftSum + rightSum + current->val);
        return max(leftSum, rightSum) + current->val;
    }
};