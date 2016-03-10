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
    int countNodes(TreeNode* root) {
        TreeNode* left = root;
        TreeNode* right = root;
        int height = 0;
        while (right) {
            right = right->right;
            left = left->left;
            ++height;
        }
        //use << instead of pow(base, power) since the pow() function a double, this will harm the efficiency
        if (left == nullptr) return (1 << height) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};