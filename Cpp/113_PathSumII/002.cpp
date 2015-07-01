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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> currentPathNodes;
        vector<vector<int>> result;
        pathSumHelper(root, sum, currentPathNodes, result);
        return result;
    }
private:
    void pathSumHelper(TreeNode* node, int sum, vector<int> currentPathNodes, vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        } else {
            currentPathNodes.push_back(node->val);
            if (node->left == nullptr && node->right == nullptr && sum == node->val) {
                result.push_back(currentPathNodes);
                return;
            } else {
                pathSumHelper(node->left, sum - node->val, currentPathNodes, result);
                pathSumHelper(node->right, sum - node->val, currentPathNodes, result);
            }
        }
    }
};
