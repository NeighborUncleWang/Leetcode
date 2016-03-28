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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> stackSuccessor;
        stack<TreeNode*> stackPredecessor;
        TreeNode* current = root;
        while (current) {
            if (current->val >= target) {
                stackSuccessor.push(current);
                current = current->left;
            } else {
                stackPredecessor.push(current);
                current = current->right;
            }
        }
        vector<int> result;
        while (k-- > 0) {
            if (!stackPredecessor.empty() && (stackSuccessor.empty() 
            || abs(stackPredecessor.top()->val - target) < abs(stackSuccessor.top()->val - target))) {
                TreeNode* current = stackPredecessor.top();
                stackPredecessor.pop();
                result.push_back(current->val);
                current = current->left;
                //这里存的是下一个closest predecessor,值比current->val更小，也就是更远离target
                while (current) {
                    stackPredecessor.push(current);
                    current = current->right;
                }
            } else {
                TreeNode* current = stackSuccessor.top();
                stackSuccessor.pop();
                result.push_back(current->val);
                current = current->right;
                //这里存的是下一个closest successor,值比current->val更大，也就是更远离target
                while (current) {
                    stackSuccessor.push(current);
                    current = current->left;
                }
            }
        }
        return result;
    }
};