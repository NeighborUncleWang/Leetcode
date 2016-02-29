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
                //2.a这代表我们是第一次traverse到current node
                //preorder traverse中在第一次traverse到current node时进行visit
                if (predecessor->right == nullptr) {
                    result.push_back(current->val);
                    predecessor->right = current;
                    current = current->left;
                } else {//2.b,这代表我们是第二次traverse到current节点
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }
        return result;
    }
};
