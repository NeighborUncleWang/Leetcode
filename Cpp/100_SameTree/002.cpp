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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(p);
        nodesQueue.push(q);
        while (!nodesQueue.empty()) {
            TreeNode* t1 = nodesQueue.front();
            nodesQueue.pop();
            TreeNode* t2 = nodesQueue.front();
            nodesQueue.pop();
            if (t1 == nullptr && t2 == nullptr) continue;
            if (t1 == nullptr || t2 == nullptr) return false;
            if (t1->val != t2->val) return false;
            nodesQueue.push(t1->left);
            nodesQueue.push(t2->left);
            nodesQueue.push(t1->right);
            nodesQueue.push(t2->right);
        }
        return true;
    }
};