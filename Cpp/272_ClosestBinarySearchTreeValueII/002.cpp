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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> nodesQueue;
        dfs(root, nodesQueue, target, k);
        vector<int> result;
        while (!nodesQueue.empty()) {
            result.push_back(nodesQueue.top().second);
            nodesQueue.pop();
        }
        return result;
    }
private:
    void dfs(TreeNode* currentNode, priority_queue<pair<double, int>>& nodesQueue,
    double target, int k) {
        if (currentNode == nullptr) {
            return;
        }
        nodesQueue.push(make_pair(abs(currentNode->val - target), currentNode->val));
        if (nodesQueue.size() > k) {
            nodesQueue.pop();
        }
        dfs(currentNode->left, nodesQueue, target, k);
        dfs(currentNode->right, nodesQueue, target, k);
    }
};