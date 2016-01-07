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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<pair<int, TreeNode*>> nodesQueue;
        map<int, vector<int>> hashMap;
        nodesQueue.emplace(0, root);
        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            hashMap[node.first].push_back(node.second->val);
            nodesQueue.pop();
            if (node.second->left) {
                nodesQueue.emplace(node.first - 1, node.second->left);
            }
            if (node.second->right) {
                nodesQueue.emplace(node.first + 1, node.second->right);
            }
        }
        vector<vector<int>> result;
        for (auto& p : hashMap) {
            result.push_back(p.second);
        }
        return result;
    }
};