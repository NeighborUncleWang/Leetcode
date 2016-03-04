/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> nodesStack;
    //push all the left subnodes to stack until reaches the lefmost node in the tree
    //use a stack to store the node during the in-order traversal
    //这个其实就是iterative in-order traversal中的一步
    void pushLeftChild(TreeNode* current) {
        while (current != nullptr) {
            nodesStack.push(current);
            current = current->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushLeftChild(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodesStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto current = nodesStack.top();
        nodesStack.pop();
        pushLeftChild(current->right);
        return current->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */