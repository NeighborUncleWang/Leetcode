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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> result;
        inorderTraversal(root, result);
        swap(result[0]->val, result[1]->val);
    }
private:
    void inorderTraversal(TreeNode* root, vector<TreeNode*>& result) {
        TreeNode *current = root, *predecessor = nullptr, *temp = nullptr;
        while (current != nullptr) {
            if (current->left == nullptr) {
                if (predecessor && predecessor->val > current->val) {
                    if (result.empty()) {
                        result.push_back(predecessor);
                        result.push_back(current);
                    } else {
                        result[1] = current;
                    }
                }
                predecessor = current;
                current = current->right;
            } else {
                temp = current->left;
                while (temp->right != nullptr && temp->right != current) {
                    temp = temp->right;
                }
                if (temp->right == nullptr) {
                    temp->right = current;
                    current = current->left;
                } else {
                    if (predecessor && predecessor->val > current->val) {
                        if (result.empty()) {
                            result.push_back(predecessor);
                            result.push_back(current);
                        } else {
                            result[1] = current;
                        }
                    }
                    predecessor = current;
                    temp->right = nullptr;
                    current = current->right;
                }
            }
        }
    }
};
