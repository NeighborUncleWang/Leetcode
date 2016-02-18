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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return helper(nums, 0, size - 1);
    }
private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (right < left) {
            return nullptr;
        }
        int middle = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = helper(nums, left, middle - 1);
        node->right = helper(nums, middle + 1, right);
        return node;
    }
};