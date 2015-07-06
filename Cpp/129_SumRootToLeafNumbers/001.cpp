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
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
private:
    int sumNumbersHelper(TreeNode* node, int sum) {
        if (node == nullptr) {
            return 0;
        }
        sum = sum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return sum;
        }
        return sumNumbersHelper(node->right, sum) + sumNumbersHelper(node->left, sum);
    }
};
