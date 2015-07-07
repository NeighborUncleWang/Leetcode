/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *parent = root, *current, *leftMost;
        if (root == nullptr) {
            return;
        }
        current = root->left;
        leftMost = root->left;
        while (current) {
            if (current == parent->left) {
                current->next = parent->right;
                current = current->next;
            } else {
                if (parent->next) {
                    parent = parent->next;
                    current->next = parent->left;
                    current = current->next;
                } else {
                    parent = leftMost;
                    leftMost = parent->left;
                    current = leftMost;
                }
            }
        }
    }
};
