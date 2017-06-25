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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            if (current->left != nullptr) {
                if (current->left->left == nullptr && current->left->right == nullptr) {
                    result += current->left->val;
                } else {
                    q.push(current->left);
                }
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        return result;
    }
};