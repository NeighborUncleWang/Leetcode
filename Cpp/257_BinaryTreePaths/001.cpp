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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper(root, "", result);
        return result;
    }
private:
    void helper(TreeNode* node, string path, vector<string>& result) {
        if (node == nullptr) {
            return;
        } else if (node->left == nullptr && node->right == nullptr) {
            path += to_string(node->val);
            result.push_back(path);
            return;
        }
        path += to_string(node->val) + "->";
        helper(node->left, path, result);
        helper(node->right, path, result);
    }
};
