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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }
private:
    void inorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorderTraversalHelper(node->left, result);
        result.push_back(node->val);
        inorderTraversalHelper(node->right, result);
    }
};
