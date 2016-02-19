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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result, 0);
        return result;
    }
private:
    void helper(TreeNode* node, vector<int>& result, int depth) {
        if (node == nullptr) {
            return;
        }
        if (depth == result.size()) {
            result.push_back(node->val);
        }
        helper(node->right, result, depth + 1);
        helper(node->left, result, depth + 1);
    }
};