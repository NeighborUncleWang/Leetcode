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
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
private:
    pair<int, int> dfs(TreeNode* current) {
        if (current == nullptr) return make_pair(0, 0);
        pair<int, int> left = dfs(current->left);
        pair<int, int> right = dfs(current->right);
        pair<int, int> result;
        //first is the result for current not robbed
        //second is current is robbed
        result.first = max(left.first, left.second) + max(right.first, right.second);
        result.second = current->val + left.first + right.first;
        return result;
    }
};