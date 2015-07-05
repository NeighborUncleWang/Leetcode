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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeHelper(p, q);
    }
private:
    bool isSameTreeHelper(TreeNode* firstTreeNode, TreeNode* secondTreeNode) {
        if (firstTreeNode == nullptr || secondTreeNode == nullptr) {
            if (firstTreeNode != nullptr || secondTreeNode != nullptr) {
                return false;
            } else {
                return true;
            }
        }
        if (firstTreeNode->val != secondTreeNode->val) {
            return false;
        }
        return isSameTreeHelper(firstTreeNode->left, secondTreeNode->left)
        && isSameTreeHelper(firstTreeNode->right, secondTreeNode->right);
    }
};
