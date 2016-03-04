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
    int kthSmallest(TreeNode* root, int k) {
        auto current = root;
        //这个while loop也可以写成递归形式
        while (current) {
            int rank = count(current->left);
            if (rank + 1 == k) {
                return current->val;
            } else if (rank + 1 > k) {
                current = current->left;
            } else {
                current = current->right;
                k -= rank + 1;
            }
        }
    }
private:
    int count(TreeNode* current) {
        if (current == nullptr) return 0;
        return count(current->left) + count(current->right) + 1;
    }
};