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
        int crossNode = INT_MIN;
        maxPathSumHelper(root, crossNode);
        return crossNode;//here we only need to return crossNode not endByNode, since the crossNode will cover the endByNode case
    }
private:
    int maxPathSumHelper(TreeNode* node, int& crossNode) {
        if (node == nullptr) {
            return 0;
        }
        int leftSum = maxPathSumHelper(node->left, crossNode);
        int rightSum = maxPathSumHelper(node->right, crossNode);
        int temp = node->val + (leftSum > 0 ? leftSum : 0) + (rightSum > 0 ? rightSum : 0);
        crossNode = max(temp, crossNode);
        return node->val + max(0, max(leftSum, rightSum));
    }
};
