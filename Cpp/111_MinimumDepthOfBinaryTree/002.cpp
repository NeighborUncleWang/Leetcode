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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        int currentLevelNodes = 1, nextLevelNodes = 0, level = 1;
        while (nodesQueue.empty() == false) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            --currentLevelNodes;
            if (node->left == nullptr && node->right == nullptr) {
                return level;
            }
            if (node->left != nullptr) {
                nodesQueue.push(node->left);
                ++nextLevelNodes;
            }
            if (node->right != nullptr) {
                nodesQueue.push(node->right);
                ++nextLevelNodes;
            }
            if (currentLevelNodes == 0) {
                ++level;
                currentLevelNodes = nextLevelNodes;
                nextLevelNodes = 0;
            }
        }
    }
};
