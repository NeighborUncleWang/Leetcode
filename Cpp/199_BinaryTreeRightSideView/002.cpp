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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        nodesQueue.push(nullptr);
        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            while (node) {
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
                if (nodesQueue.front() == nullptr) {
                    result.push_back(node->val);
                }
                node = nodesQueue.front();
                nodesQueue.pop();
            }
            //push nullptr into the queue at the end of each level
            if (!nodesQueue.empty()) {
                nodesQueue.push(nullptr);
            }
        }
        return result;
    }
};
