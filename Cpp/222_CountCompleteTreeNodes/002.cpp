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
private:
    int height(TreeNode* current) {
        int height = -1;
        while (current) {
            current = current->left;
            ++height;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h < 0) return 0;
        if (height(root->right) == h - 1) {
            return (1 << h) + countNodes(root->right);
        } else {
            return (1 << h - 1) + countNodes(root->left);
        }
    }
};