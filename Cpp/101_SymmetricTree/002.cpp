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
        if (root == nullptr) return true;
        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;
        leftQueue.push(root->left);
        rightQueue.push(root->right);
        while (!leftQueue.empty()) {
            auto left = leftQueue.front();
            leftQueue.pop();
            auto right = rightQueue.front();
            rightQueue.pop();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;
            leftQueue.push(left->left);
            leftQueue.push(left->right);
            rightQueue.push(right->right);
            rightQueue.push(right->left);
        }
        return true;
    }
};