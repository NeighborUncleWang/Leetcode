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
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int nodesCurrentLevel = 1, nodesNextLevel = 0;
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            --nodesCurrentLevel;
            level.push_back(node->val);
            if (node->left != nullptr) {
                nodeQueue.push(node->left);
                ++nodesNextLevel;
            }
            if (node->right != nullptr) {
                nodeQueue.push(node->right);
                ++nodesNextLevel;
            }
            if (nodesCurrentLevel == 0) {
                result.push_back(level);
                level.clear();
                nodesCurrentLevel = nodesNextLevel;
                nodesNextLevel = 0;
            }
        }
        return result;
    }
};
