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
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        vector<int> level;
        int nodesCurrentLevel = 1, nodesNextLevel = 0;
        while (!nodesQueue.empty()) {
            TreeNode *node = nodesQueue.front();
            nodesQueue.pop();
            --nodesCurrentLevel;
            level.push_back(node->val);
            if (node->left != nullptr) {
                ++nodesNextLevel;
                nodesQueue.push(node->left);
            }
            if (node->right != nullptr) {
                ++nodesNextLevel;
                nodesQueue.push(node->right);
            }
            if (nodesCurrentLevel == 0) {
                result.push_back(level);
                nodesCurrentLevel = nodesNextLevel;
                nodesNextLevel = 0;
                level.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
