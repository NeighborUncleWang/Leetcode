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
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        vector<int> nodesInOneLevel;
        deque<TreeNode*> nodesQueue;
        nodesQueue.push_back(root);
        int currentLevelNodes = 1;
        int nextLevelNodes = 0;
        int level = 0;
        while (!nodesQueue.empty()) {
            if (level % 2) {
                TreeNode *node = nodesQueue.back();//back
                nodesQueue.pop_back();
                nodesInOneLevel.push_back(node->val);
                --currentLevelNodes;
                if (node->right) {
                    nodesQueue.push_front(node->right);//first push_front(right)
                    ++nextLevelNodes;
                }
                if (node->left) {
                    nodesQueue.push_front(node->left);
                    ++nextLevelNodes;
                }
            }
            if (level % 2 == 0) {
                TreeNode *node = nodesQueue.front();//front
                nodesQueue.pop_front();
                nodesInOneLevel.push_back(node->val);
                --currentLevelNodes;
                if (node->left) {
                    nodesQueue.push_back(node->left);//first push_back(left)
                    ++nextLevelNodes;
                }
                if (node->right) {
                    nodesQueue.push_back(node->right);
                    ++nextLevelNodes;
                }
            }
            if (currentLevelNodes == 0) {
                result.push_back(nodesInOneLevel);
                currentLevelNodes = nextLevelNodes;
                nextLevelNodes = 0;
                nodesInOneLevel.clear();
                ++level;
            }
        }
        return result;
    }
};
