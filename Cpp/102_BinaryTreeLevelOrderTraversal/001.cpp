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
        if (root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> nodesQueue;
        vector<vector<int>> result;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                auto node = nodesQueue.front();
                nodesQueue.pop();
                level.push_back(node->val);
                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }
            result.push_back(move(level));
        }
        return result;
    }
};