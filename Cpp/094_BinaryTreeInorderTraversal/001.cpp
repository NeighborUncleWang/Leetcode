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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        auto currentNode = root;
        while (currentNode != nullptr || !st.empty()) {
            if (currentNode != nullptr) {
                st.push(currentNode);
                currentNode = currentNode->left;
            } else {
                currentNode = st.top();
                st.pop();
                result.push_back(currentNode->val);
                currentNode = currentNode->right;
            }
        }
        return result;
    }
};