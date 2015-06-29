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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode *last_node_visited = nullptr;
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                auto peek_node = st.top();
                if (peek_node->right != nullptr && last_node_visited != peek_node->right) {
                    root = peek_node->right;
                } else {
                    result.push_back(peek_node->val);
                    last_node_visited = peek_node;
                    st.pop();
                }
            }
        }
        return result;
    }
};
