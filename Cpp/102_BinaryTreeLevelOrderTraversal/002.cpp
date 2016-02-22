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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
private:
    void dfs(TreeNode* current, int depth, vector<vector<int>>& result) {
        if (current == nullptr) {
            return;
        }
        if (result.size() == depth) {
            result.push_back(vector<int>());
            //这里千万别加return;
        }
        //无论preorder,postorder,inorder这题都能AC
        //只要保证先traverse current->left再traverse current->right
        dfs(current->left, depth + 1, result);
        dfs(current->right, depth + 1, result);
        result[depth].push_back(current->val);
    }
};