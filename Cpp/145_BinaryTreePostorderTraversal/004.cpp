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
        //use preoder root->right->left
        //then reverse
        auto currentNode = root;
        while (currentNode != nullptr || !st.empty()) {
            if (currentNode != nullptr) {
                result.push_back(currentNode->val);
                if (currentNode->left) {
                    st.push(currentNode->left);
                }
                currentNode = currentNode->right;
            } else {
                currentNode = st.top();
                st.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
