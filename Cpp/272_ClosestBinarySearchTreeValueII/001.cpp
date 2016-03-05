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
            if (stackSuccessor.empty()) {
                result.push_back(getNextPredecessor(stackPredecessor));
            } else if (stackPredecessor.empty()) {
                result.push_back(getNextSuccessor(stackSuccessor));
            } else {
                double diffPredecessor = abs(stackPredecessor.top()->val - target);
                double diffSuccessor = abs(stackSuccessor.top()->val - target);
                if (diffPredecessor < diffSuccessor) {
                    result.push_back(getNextPredecessor(stackPredecessor));
                } else {
                    result.push_back(getNextSuccessor(stackSuccessor));
                }
            }
        }
        return result;
    }
private:
    int getNextSuccessor(stack<TreeNode*>& stackSuccessor) {
        TreeNode* current = stackSuccessor.top();
        stackSuccessor.pop();
        int result = current->val;
        current= current->right;
        while (current) {
            stackSuccessor.push(current);
            current = current->left;
        }
        return result;
    }
    int getNextPredecessor(stack<TreeNode*>& stackPredecessor) {
        TreeNode* current = stackPredecessor.top();
        stackPredecessor.pop();
        int result = current->val;
        current = current->left;
        while (current) {
            stackPredecessor.push(current);
            current = current->right;
        }
        return result;
    }
};