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
    bool AreIdentical(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        } else if (s == nullptr || t == nullptr) {
            return false;
        }
        return s->val == t->val && AreIdentical(s->left, t->left) && AreIdentical(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr) return true;
        if (s == nullptr) return false;
        return AreIdentical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};