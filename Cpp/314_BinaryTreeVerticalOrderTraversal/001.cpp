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
        map<int, vector<int>> treeMap;
        //queue不能用{}初始化
        queue<pair<int, TreeNode*>> nodesQueue;
        nodesQueue.emplace(0, root);
        while (!nodesQueue.empty()) {
            TreeNode* node = nodesQueue.front().second;
            int column = nodesQueue.front().first;
            nodesQueue.pop();
            treeMap[column].push_back(node->val);
            if (node->left) {
                nodesQueue.emplace(column - 1, node->left);
            }
            if (node->right) {
                nodesQueue.emplace(column + 1, node->right);
            }
        }
        vector<vector<int>> result;
        //这里pair必须用const int
        //map和unordered_map的value_type都是pair<const Key, T>
        for (pair<const int, vector<int>>& iter : treeMap) {
            result.push_back(move(iter.second));
        }
        return result;
    }
};