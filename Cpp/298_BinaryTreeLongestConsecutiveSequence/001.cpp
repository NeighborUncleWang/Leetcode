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
    int longestConsecutive(TreeNode* root) {
        int maxLength = 0;
        helper(root, nullptr, 1, maxLength);
        return maxLength;
    }
private:
    void helper(TreeNode* currentNode, TreeNode* parent, int currentLength, int& maxLength) {
        if (currentNode == nullptr) return;
        if (parent && currentNode->val == parent->val + 1) {
            ++currentLength;
        } else {
            currentLength = 1;
        }
        maxLength = max(maxLength, currentLength);
        helper(currentNode->left, currentNode, currentLength, maxLength);
        helper(currentNode->right, currentNode, currentLength, maxLength);
    }
};