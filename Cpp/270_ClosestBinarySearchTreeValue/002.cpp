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
        int nodeValue = root->val;
        TreeNode* child = nodeValue < target ? root->right : root->left;
        if (nodeValue == target || child == nullptr) {
            return nodeValue;
        }
        int childClosest = closestValue(child, target);
        return abs(nodeValue - target) < abs(childClosest - target) ? nodeValue : childClosest;
    }
};