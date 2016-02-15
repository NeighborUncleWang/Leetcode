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
        auto currentNode = root;
        while (currentNode != nullptr || !st.empty()) {
            if (currentNode != nullptr) {
                st.push(currentNode);
                currentNode = currentNode->left;
            } else {
                auto peek_node = st.top();
                // if right child exists and traversing node
                // from left child, then move right
                // 如果last_node_visited == peek_node->right的话
                // 说明此时right subtree刚刚visit结束，这时应该visit peek_node
                // 所以这种情况应该算到else里面
                // 根据wikipedia的图，其实一个node会被visit三次
                if (peek_node->right != nullptr && last_node_visited != peek_node->right) {
                    currentNode = peek_node->right;
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
