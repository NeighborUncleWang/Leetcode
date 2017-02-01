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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; ++i) {
            hashMap[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, 0, n - 1, postorder, 0, n - 1, hashMap);
    }
    TreeNode* buildTreeHelper(const vector<int>& inorder, int inLeft, int inRight,
    const vector<int>& postorder, int postLeft, int postRight, unordered_map<int, int>& hashMap) {
        if (postLeft > postRight) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postRight]);
        int index = hashMap[postorder[postRight]];
        root->left = buildTreeHelper(inorder, inLeft, index - 1, postorder, postLeft, postLeft + index - inLeft - 1, hashMap);
        root->right = buildTreeHelper(inorder, index + 1, inRight, postorder, postLeft + index - inLeft, postRight - 1, hashMap);
        return root;
    }
};