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
    void recoverTree(TreeNode* root) {
        TreeNode* predecessor = nullptr;
        TreeNode* firstElement = nullptr;
        TreeNode* secondElement = nullptr;
        traverse(root, predecessor, firstElement, secondElement);
        swap(firstElement->val, secondElement->val);
    }
private:
    void traverse(TreeNode* current, TreeNode*& predecessor, 
        TreeNode*& firstElement, TreeNode*& secondElement) {
        //这里不能写成if (current === nullptr || firstElement && secondElement)
        if (current == nullptr) {
            return;
        }
        traverse(current->left, predecessor, firstElement, secondElement);
        if (predecessor != nullptr && predecessor->val > current->val) {
                //if firstElement is nullptr, update both
                //因为有可能firstElement和secondElement都被赋值
                //考虑两个互换的element inorder traversal时刚好相邻的情况
            if (firstElement == nullptr) {
                firstElement = predecessor;
                secondElement = current;
            } else {
                secondElement = current;
            }
        }
        predecessor = current;
        traverse(current->right, predecessor, firstElement, secondElement);
    }
};