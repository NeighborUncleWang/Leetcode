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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> result;
        while (current != NULL) {
            if (current->left == NULL) {
                result.push_back(current->val);
                current = current->right;
            } else {
                //find the predecessor of current
                auto predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                //2.a,这代表我们是第一次traverse到current node
                //inorder traverse中在第二次traverse到current node时才进行visit
                if (predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                } else {//2.b，这代表我们是第二次traverse到current节点
                    predecessor->right = NULL;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};