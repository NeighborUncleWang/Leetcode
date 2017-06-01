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
    string Preorder(TreeNode* t) {
        auto cur = t;
        stack<TreeNode*> st;
        string res;
        while (cur || !st.empty()) {
            if (cur) {
                //这里分隔符,要写在val前面而不是后面
                //否则[12],[2]这个case过不去
                res += "," + to_string(cur->val);
                st.push(cur);
                cur = cur->left;
            } else {
                res += ",#";
                cur = st.top()->right;
                st.pop();
            }
        }
        res += ",#";
        return res;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return Preorder(s).find(Preorder(t)) != string::npos;
    }
};