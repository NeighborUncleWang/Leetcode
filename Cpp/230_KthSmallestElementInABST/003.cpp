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
        vector<int> result;
        int index = 0;
        inOrderTraversal(root, result, index, k);
        return result.back();
    }
private:
    void inOrderTraversal(TreeNode* node, vector<int>& result, int& index, int k) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left, result, index, k);
        if (index == k) {
            return;
        }
        result.push_back(node->val);
        ++index;
        inOrderTraversal(node->right, result, index, k);
    }
};
