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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>{};
        }
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> result;
        for (int i = start; i <= end; ++i) {
            auto leftSubtrees = helper(start, i - 1);
            auto rightSubtrees = helper(i + 1, end);
            for (auto left : leftSubtrees) {
                for (auto right : rightSubtrees) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};