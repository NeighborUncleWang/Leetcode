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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr) {
            return result;
        }
        string sequence;
        ConstructPaths(root, sequence, result);
        return result;
    }
private:
    void ConstructPaths(TreeNode* node, string& sequence, vector<string>& result) {
        //if the node is leaf
        if (node->left == nullptr && node->right == nullptr) {
            string value = to_string(node->val);
            sequence += value;
            result.push_back(sequence);
            sequence.resize(sequence.size() - value.size());
            return;
        }
        string value = to_string(node->val) + "->";
        sequence += value;
        if (node->left) {
            ConstructPaths(node->left, sequence, result);
        }
        if (node->right) {
            ConstructPaths(node->right, sequence, result);
        }
        sequence.resize(sequence.size() - value.size());
    }
};
