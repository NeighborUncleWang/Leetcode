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
    int closestValue(TreeNode* root, double target) {
        int closestValue = root->val;
        TreeNode* current = root;
        while (current) {
            if (abs(current->val - target) < abs(closestValue - target)) {
                closestValue = current->val;
            }
            if (current->val < target) {
                current = current->right;
            } else if (current->val > target) {
                current = current->left;
            } else {
                break;
            }
        }
        return closestValue;
    }
};