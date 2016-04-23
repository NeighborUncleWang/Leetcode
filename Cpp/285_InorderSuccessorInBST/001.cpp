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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* current = root;
        TreeNode* successor = nullptr;
        while (current) {
            //这里必须是<=而不是<
            //否则case[0], output: 0, expected:nullptr会通不过
            //必须当current->val > p->val的时候
            //current才有可能成为successor的candidate
            if (current->val <= p->val) {
                current = current->right;
            } else {
                successor = current;
                current = current->left;
            }
        }
        return successor;
    }
};