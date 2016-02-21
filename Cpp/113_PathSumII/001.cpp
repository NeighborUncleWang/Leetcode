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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, sum, result, path);
        return result;
    }
private:
    void dfs(TreeNode* node, int sum, vector<vector<int>>& result, vector<int>& path) {
        if (node == nullptr) {
            return;
        } else if (node->left == nullptr && node->right == nullptr && sum - node->val == 0) {
            path.push_back(node->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node->val);
        sum -= node->val;
        dfs(node->left, sum, result, path);
        dfs(node->right, sum, result, path);
        path.pop_back();
    }
};