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
        return generateTreesHelper(1, n);
    }
private:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> subTrees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubTrees = generateTreesHelper(start, i - 1);
            vector<TreeNode*> rightSubTrees = generateTreesHelper(i + 1, end);
            for (int j = 0; j < leftSubTrees.size(); ++j) {
                for (int k = 0; k < rightSubTrees.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTrees[j];
                    root->right = rightSubTrees[k];
                    subTrees.push_back(root);
                }
            }
        }
        return subTrees;
    }
};
