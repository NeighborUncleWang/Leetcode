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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; ++i) {
            hashMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1, hashMap);
    }
    TreeNode* buildTreeHelper(const vector<int>& preorder, int preLeft, int preRight,
    const vector<int>& inorder, int inLeft, int inRight, unordered_map<int, int>& hashMap) {
        if (preLeft > preRight) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preLeft]);
        int index = hashMap[preorder[preLeft]];
        root->left = buildTreeHelper(preorder, preLeft + 1, preLeft + index - inLeft,
        inorder, inLeft, index - 1, hashMap);
        root->right = buildTreeHelper(preorder, preLeft + index - inLeft + 1, preRight,
        inorder, index + 1, inRight, hashMap);
        return root;
    }
};
