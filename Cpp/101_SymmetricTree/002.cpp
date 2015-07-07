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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> leftHalfNodes;
        queue<TreeNode*> rightHalfNodes;
        leftHalfNodes.push(root->left);
        rightHalfNodes.push(root->right);
        while (leftHalfNodes.empty() == false) {
            auto left = leftHalfNodes.front();
            leftHalfNodes.pop();
            auto right = rightHalfNodes.front();
            rightHalfNodes.pop();
            if (left == nullptr && right != nullptr || left != nullptr && right == nullptr) {
                return false;
            }
            if (left != nullptr && right != nullptr && left->val != right->val) {
                return false;
            }
            if (left != nullptr) {
                leftHalfNodes.push(left->left);
                leftHalfNodes.push(left->right);
            }
            if (right != nullptr) {
                rightHalfNodes.push(right->right);
                rightHalfNodes.push(right->left);
            }
        }
        return true;
    }
};
