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
        TreeNode *predecessor = nullptr, *current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                result.push_back(current->val);
                current = current->right;
            } else {
                predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {//2.a
                    result.push_back(current->val);
                    predecessor->right = current;
                    current = current->left;
                } else {//2.b
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }
        return result;
    }
};
