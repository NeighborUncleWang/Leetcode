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
        auto dummy = new TreeNode(0);
        dummy->left = root;
        auto current = dummy;
        while (current != nullptr) {
            if (current->left == nullptr) {
                current = current->right;
            } else {
                auto predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    reverseAddNodes(current->left, predecessor, result);
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }
        delete dummy;
        return result;
    }
private:
    void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& result) {
        reverse(start, end);
        auto iter = end;
        while (iter != start) {
            result.push_back(iter->val);
            iter = iter->right;
        }
        result.push_back(iter->val);
        reverse(end, start);
    }
    void reverse(TreeNode *start, TreeNode *end) {
        auto predecessor = start;
        auto current = start->right;
        while (predecessor != end) {
            auto next = current->right;
            current->right = predecessor;
            predecessor = current;
            current = next;
        }
    }
};