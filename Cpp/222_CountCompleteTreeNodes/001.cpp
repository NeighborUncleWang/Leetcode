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
        int leftDepth = 0;
        int rightDepth = 0;
        auto leftChild = root;
        while (leftChild) {
            leftChild = leftChild->left;
            ++leftDepth;
        }
        auto rightChild = root;
        while (rightChild) {
            rightChild = rightChild->right;
            ++rightDepth;
        }
        if (leftDepth == rightDepth) {
            //use << instead of pow(base, power)
            return (1 << leftDepth) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
