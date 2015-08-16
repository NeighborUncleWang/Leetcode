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
        stack<TreeNode*> nodesStack;
        vector<int> result;
        auto node = root;
        int i = 0;
        while (node || !nodesStack.empty()) {
            if (node != nullptr) {
                nodesStack.push(node);
                node = node->left;
            } else {
                result.push_back(nodesStack.top()->val);
                ++i;
                if (i == k) {
                    return result.back();
                }
                node = nodesStack.top()->right;
                nodesStack.pop();
            }
        }
    }
};
