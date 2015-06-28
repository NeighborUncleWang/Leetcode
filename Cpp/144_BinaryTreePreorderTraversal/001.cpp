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
        stack<TreeNode*> st;
        vector<int> result;
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                result.push_back(root->val);
                st.push(root);
                root = root->left;
            } else {
                root = st.top()->right;
                st.pop();
            }
        }
        return result;
    }
};
