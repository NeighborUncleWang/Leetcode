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
        stack<TreeNode*> st;
        auto current = root;
        while (current || !st.empty()) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                if (--k == 0) {
                    return current->val;
                }
                current = current->right;
            }
        }
    }
};