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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
private:
    bool helper(TreeNode* node, int& count) {
        if (node == nullptr) {
            return true;
        }
        bool left = helper(node->left, count);
        bool right = helper(node->right, count);
        if (left && right
        && (node->left == nullptr || node->left->val == node->val)
        && (node->right == nullptr || node->right->val == node->val)) {
            ++count;
            return true;
        }
        return false;
    }
};