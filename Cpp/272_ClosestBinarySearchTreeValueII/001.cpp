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
        TreeNode* currentNode = root;
        while (currentNode) {
            if (currentNode->val >= target) {
                stackSuccessor.push(currentNode);
                currentNode = currentNode->left;
            } else {
                stackPredecessor.push(currentNode);
                currentNode = currentNode->right;
            }
        }
        vector<int> result;
        while (k > 0) {
            if (stackSuccessor.empty()) {
                result.push_back(getNextPredecessor(stackPredecessor));
            } else if (stackPredecessor.empty()) {
                result.push_back(getNextSuccessor(stackSuccessor));
            } else if (stackSuccessor.val)
        }
    }
private:
    int getNextSuccessor(stack<TreeNode*>& stackSucessor) {
        TreeNode* node = stackSuccessor.top();
        stackSuccessor.pop();
        TreeNode* currentNode= node->right;
        while (currentNode) {
            stackSuccessor.push(currentNode);
            currentNode = current->right;
        }
        return node->val;
    }
    int getNextPredecessor(stack<TreeNode*>& stackPredecessor) {
        TreeNode* node = stackPredecessor.top();
        stackPredecessor.pop();
        TreeNode* currentNode = node->left;
        while (currentNode) {
            stackPredecessor.push(currentNode);
            currentNode = currentNode->right;
        }
        return node->val;
    }
};