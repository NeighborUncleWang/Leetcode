class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> result;
        TreeNode *predecessor = nullptr;
        inorderTraversal(root, predecessor, result);
        swap(result[0]->val, result[1]->val);
    }
private:
    void inorderTraversal(TreeNode *current, TreeNode*& predecessor, vector<TreeNode*>& result) {
        if (current == nullptr) {
            return;
        }
        inorderTraversal(current->left, predecessor, result);
        if (predecessor && predecessor->val > current->val) {
            if (result.empty()) {
                result.push_back(predecessor);
                result.push_back(current);
            } else {
                result[1] = current;
            }
        }
        predecessor = current;
        inorderTraversal(current->right, predecessor, result);
    }
    
};

