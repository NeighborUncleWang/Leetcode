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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        auto node = root;
        while (node != nullptr || !st.empty()) {
            if (node != nullptr) {
                result.push_back(node->val);
                if (node->right != nullptr) {
                    st.push(node->right);
                }
                node = node->left;
            } else {
                node = st.top();
                st.pop();
            }
        }
        return result;
    }
};