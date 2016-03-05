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
        queue<int> result;
        inorder(root, target, k, result);
        vector<int> closest;
        while (!result.empty()) {
            closest.push_back(result.front());
            result.pop();
        }
        return closest;
    }
private:
    void inorder(TreeNode* current, double target, int k, queue<int>& result) {
        if (current == nullptr) return;
        inorder(current->left, target, k, result);
        if (result.size() == k) {
            if (abs(current->val - target) < abs(result.front() - target)) {
                result.pop();
            } else {
                return;
            }
        }
        result.push(current->val);
        inorder(current->right, target, k, result);
    }  
};