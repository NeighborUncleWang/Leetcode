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
public:
    BSTIterator(TreeNode *root) {
        ptr = root;
        pushLeftChild(ptr);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodesStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto node = nodesStack.top();
        nodesStack.pop();
        auto temp = node->val;
        pushLeftChild(node->right);
        return temp;
    }
private:
    TreeNode* ptr;
    stack<TreeNode*> nodesStack;
	//push all the left subnodes to stack until reaches the lefmost node in the tree
	//use a stack to store the node during the in-order traversal
    void pushLeftChild(TreeNode* node) {
        while (node != nullptr) {
            nodesStack.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
