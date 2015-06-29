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
        int n = nums.size();
        if (n == 0) {
            return nullptr;
        }
        return constructBST(0, n - 1, nums);
    }
private:
    TreeNode* constructBST(int imin, int imax, vector<int>& nums) {
        if (imin > imax) {
            return nullptr;
        }
        int imid = imin + (imax - imin) / 2;
        TreeNode *root = new TreeNode(nums[imid]);
        root->left = constructBST(imin, imid - 1, nums);
        root->right = constructBST(imid + 1, imax, nums);
        return root;
    }
};
