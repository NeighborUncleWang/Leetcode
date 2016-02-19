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
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodesQueue.front();
                nodesQueue.pop();
                if (node->left != nullptr) {
                    nodesQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    nodesQueue.push(node->right);
                }
                if (i == size - 1) {
                    result.push_back(node->val);
                }
            }
        }
        return result;
    }
};