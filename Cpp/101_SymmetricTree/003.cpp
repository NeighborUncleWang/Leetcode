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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        int currentLevelNodes = 1;
        int nextLevelNodes = 0;
        vector<TreeNode*> level;
        while (nodesQueue.empty() == false) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            level.push_back(node);
            --currentLevelNodes;
            if (node != nullptr) {
                nodesQueue.push(node->left);
                nodesQueue.push(node->right);
                nextLevelNodes += 2;
            }
            if (currentLevelNodes == 0) {
                int start = 0;
                int end = level.size() - 1;
                while (start < end) {
                    if (level[start] == nullptr && level[end] != nullptr
                    || level[start] != nullptr && level[end] == nullptr) {
                        return false;
                    }
                    if (level[start] != nullptr && level[end] != nullptr
                    && level[start]->val != level[end]->val) {
                        return false;
                    }
                    ++start;
                    --end;
                }
                currentLevelNodes = nextLevelNodes;
                nextLevelNodes = 0;
                level.clear();
            }
        }
        return true;
    }
};
