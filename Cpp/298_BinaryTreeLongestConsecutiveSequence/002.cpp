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
        return dfs(nullptr, root, 0);
    }
private:
    int dfs(TreeNode* parent, TreeNode* currentNode, int currentLength) {
        if (currentNode == nullptr) return currentLength;
        currentLength = parent && parent->val + 1 == currentNode->val? currentLength + 1 : 1;
        return max(currentLength, max(dfs(currentNode, currentNode->left, currentLength), 
        dfs(currentNode, currentNode->right, currentLength)));
    }
};