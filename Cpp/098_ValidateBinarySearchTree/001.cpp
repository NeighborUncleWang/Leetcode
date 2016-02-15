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
    bool isValidBST(TreeNode* root) {
        TreeNode* predecessor = nullptr;
        return isValidBSTHelper(root, predecessor);
    }
private:
    bool isValidBSTHelper(TreeNode* current, TreeNode*& predecessor) {
        if (current == nullptr) {
            return true;
        }
        if (!isValidBSTHelper(current->left, predecessor)) return false;
        if (predecessor != nullptr && predecessor->val >= current->val) {
            return false;
        }
        //之所以这里update,是因为到这里才真正发生visit
        //wikipedia上tree traversal其实每个点被绕了3次
        //in-order traversal在中间那次才发生visit node
        predecessor = current;
        return isValidBSTHelper(current->right, predecessor);
    }
};