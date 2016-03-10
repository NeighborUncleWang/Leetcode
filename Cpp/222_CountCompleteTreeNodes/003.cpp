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
private:
    int height(TreeNode* current) {
        int height = -1;
        while (current) {
            current = current->left;
            ++height;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        auto current = root;
        int h = height(root);
        int result = 0;
        while (current) {
            if (height(current->right) == h - 1) {
                result += (1 << h);
                current = current->right;
            } else {
                result += (1 << h - 1);
                current = current->left;
            }
            --h;
        }
        return result;
    }
};