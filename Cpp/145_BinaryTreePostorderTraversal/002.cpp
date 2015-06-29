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
        TreeNode *dummy = new TreeNode(0);
        TreeNode *predecessor = nullptr;
        dummy->left = root;
        TreeNode *current = dummy;
        while (current != nullptr) {
            if (current->left == nullptr) {
                current = current->right;
            } else {
                predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    reverse(current->left, predecessor);
                    auto iterator = predecessor;
                    while (iterator != current->left) {
                        result.push_back(iterator->val);
                        iterator = iterator->right;
                    }
                    result.push_back(iterator->val);
                    reverse(predecessor, current->left);
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }
        delete dummy;
        return result;
    }
private:
    void reverse(TreeNode *start, TreeNode *end) {
        TreeNode *predecessor = start, *current = start->right, *next;
        while (predecessor != end) {
            next = current->right;
            current->right = predecessor;
            predecessor = current;
            current = next;
        }
    }
};
