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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        int currentLevelNodes = 1, nextLevelNodes = 0, level = 0;
        while (nodesQueue.empty() == false) {
            TreeNode *node = nodesQueue.front();
            nodesQueue.pop();
            --currentLevelNodes;
            if (node->left) {
                nodesQueue.push(node->left);
                ++nextLevelNodes;
            }
            if (node->right) {
                nodesQueue.push(node->right);
                ++nextLevelNodes;
            }
            if (currentLevelNodes == 0) {
                ++level;
                currentLevelNodes = nextLevelNodes;
                nextLevelNodes = 0;
            }
        }
        return level;
    }
};
