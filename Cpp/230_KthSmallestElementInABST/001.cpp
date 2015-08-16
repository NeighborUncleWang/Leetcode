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
        while (root) {
            int n = getSize(root->left);
            if (n + 1 == k) {
                return root->val;
            } else if (n + 1 > k) {
                root = root->left;
            } else {
                root = root->right;
                k = k - n - 1;
            }
        }
    }
private:
    int getSize(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return getSize(node->left) + getSize(node->right) + 1;
        }
    }
};
