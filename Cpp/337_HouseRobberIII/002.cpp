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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> hashMap;
        return dfs(root, hashMap);
    }
private:
    int dfs(TreeNode* current, unordered_map<TreeNode*, int>& hashMap) {
        if (current == nullptr) return 0;
        if (hashMap.find(current) != hashMap.end()) {
            return hashMap[current];
        }
        int val = current->val;
        if (current->left) {
            val += dfs(current->left->left, hashMap) + dfs(current->left->right, hashMap);
        }
        if (current->right) {
            val += dfs(current->right->left, hashMap) + dfs(current->right->right, hashMap);
        }
        hashMap[current] = max(val, dfs(current->left, hashMap) + dfs(current->right, hashMap));
        return hashMap[current];
    }
};