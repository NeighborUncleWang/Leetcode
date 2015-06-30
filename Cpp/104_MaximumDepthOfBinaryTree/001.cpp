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
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root);//actually I can delete maxDepthHelper and put the code into maxDepth, the speed is still 8ms
    }
    int maxDepthHelper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return max(maxDepthHelper(node->left), maxDepthHelper(node->right)) + 1;
        }
    }
};
