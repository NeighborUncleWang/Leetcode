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
    void flatten(TreeNode* root) {
        TreeNode* predecessor = nullptr;
        helper(root, predecessor);
    }
private:
    void helper(TreeNode* current, TreeNode*& predecessor) {
        if (current == nullptr) return;
        //按照right,left,root的顺序遍历节点
        //刚好把preorder traversal反过来
        //这样的话每个current->right就是这种遍历方法的predecessor，
        //对应preorder traversal中each node's right child points to the successor
        helper(current->right, predecessor);
        helper(current->left, predecessor);
        current->right = predecessor;
        current->left = nullptr;
        predecessor = current;
    }
};