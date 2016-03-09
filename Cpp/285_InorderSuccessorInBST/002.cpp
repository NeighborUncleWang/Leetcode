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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return nullptr;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            auto left = inorderSuccessor(root->left, p);
            //这里就是检查是否traverse到leaf了
            //如果left == nullptr，那么这时的root就是successor
            //如果left != nullptr,说明left这时已经被更新成sccessor
            //所以只要把结果return回去就行
            return left == nullptr ? root : left;
        }
    }
};