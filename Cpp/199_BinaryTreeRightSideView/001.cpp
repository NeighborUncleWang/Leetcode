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
        int currentLevel = 1;
        int nextLevel = 0;
        while (nodesQueue.empty() == false) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            --currentLevel;
            if (node->left) {
                nodesQueue.push(node->left);
                ++nextLevel;
            }
            if (node->right) {
                nodesQueue.push(node->right);
                ++nextLevel;
            }
            if (currentLevel == 0) {
                result.push_back(node->val);
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }
        return result;
    }
};
