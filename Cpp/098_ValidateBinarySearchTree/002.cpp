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
        stack<TreeNode*> st;
        auto current = root;
        TreeNode* previous = nullptr;
        while (current != nullptr || !st.empty()) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                if (previous != nullptr && current->val <= previous->val) {
                    return false;
                }
                st.pop();
                previous = current;
                current = current->right;
            }
        }
        return true;
    }
};