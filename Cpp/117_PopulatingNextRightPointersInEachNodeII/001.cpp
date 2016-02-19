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
        TreeLinkNode* head = nullptr;//head stores the first non-null element of next level
        TreeLinkNode* predecessor = nullptr;//predecessor stores the last visited element of next level
        TreeLinkNode* current = root;//current stores current element of current level
        while (current) {
            while (current) {
                if (current->left) {
                    if (predecessor) {
                        predecessor->next = current->left;
                    } else {
                        head = current->left;
                    }
                    predecessor = current->left;
                }
                if (current->right) {
                    if (predecessor) {
                        predecessor->next = current->right;
                    } else {
                        head = current->right;
                    }
                    predecessor = current->right;
                }
                current = current->next;
            }
            current = head;
            head = nullptr;
            predecessor = nullptr;
        }
    }
};