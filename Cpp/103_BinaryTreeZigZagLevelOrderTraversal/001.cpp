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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        vector<vector<int>> result;
        bool leftToRight = true;
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                auto node = nodesQueue.front();
                nodesQueue.pop();
                int index = leftToRight ? i : size - 1 - i;
                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            result.push_back(move(row));
            leftToRight = !leftToRight;
        }
        return result;
    }
};