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
    int dfs(TreeNode* current, vector<vector<int>>& result) {
        if (current == nullptr) {
            return 0;
        }
        int level = max(dfs(current->left, result), dfs(current->right, result));
        if (result.size() == level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(current->val);
        return level + 1;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, result);
        return result;
    }
};