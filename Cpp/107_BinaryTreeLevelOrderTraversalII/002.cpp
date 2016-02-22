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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return vector<vector<int>>(result.rbegin(), result.rend());
    }
private:
    void dfs(TreeNode* current, int depth, vector<vector<int>>& result) {
        if (current == nullptr) {
            return;
        } else if (result.size() == depth) {
            result.push_back(vector<int>());
        }
        dfs(current->left, depth + 1, result);
        dfs(current->right, depth + 1, result);
        result[depth].push_back(current->val);
    }
};