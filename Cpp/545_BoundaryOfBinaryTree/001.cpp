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
private:
    void PrintLeftBoundary(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) return;
        if (cur->left) {
            res.push_back(cur->val);
            PrintLeftBoundary(cur->left, res);
        } else if (cur->right) {
            res.push_back(cur->val);
            PrintLeftBoundary(cur->right, res);
        }
    }
    void PrintRightBoundary(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) return;
        if (cur->right) {
            PrintRightBoundary(cur->right, res);
            res.push_back(cur->val);
        } else if (cur->left) {
            PrintRightBoundary(cur->left, res);
            res.push_back(cur->val);
        }
    }
    void PrintLeaves(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) return;
        if (cur->left == nullptr && cur->right == nullptr) {
            res.push_back(cur->val);
            return;
        }
        PrintLeaves(cur->left, res);
        PrintLeaves(cur->right, res);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return vector<int>();
        vector<int> res;
        //这里一定要把root单独拿出来print
        //不能省掉这句然后PrintLeftBoundary(root, res);
        //否则会有重复的元素
        res.push_back(root->val);
        PrintLeftBoundary(root->left, res);
        PrintLeaves(root->left, res);
        PrintLeaves(root->right, res);
        PrintRightBoundary(root->right, res);
        return res;
    }
};