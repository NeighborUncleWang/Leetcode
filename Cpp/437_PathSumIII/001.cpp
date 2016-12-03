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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        unordered_map<int, int> sum_map{{0, 1}};
        return helper(root, 0, sum, sum_map);
    }
private:
    int helper(TreeNode* current, int pre_sum, int target, unordered_map<int, int>& sum_map) {
        if (current == nullptr) return 0;
        pre_sum += current->val;
        int result = sum_map[pre_sum - target];
        ++sum_map[pre_sum];
        result += helper(current->left, pre_sum, target, sum_map) + helper(current->right, pre_sum, target, sum_map);
        --sum_map[pre_sum];
        return result;
    }
};