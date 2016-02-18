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
        if (root == nullptr) return;
        auto iter = root;
        while (iter->left) {
            //其实每次for loop都是把current下面一层的nodes的next连好
            //所以才要判断iter->left而不是iter
            //因为连的其实是iter下面那一层的节点
            auto current = iter;
            while (current) {
                current->left->next = current->right;
                if (current->next) {
                    current->right->next = current->next->left;
                }
                current = current->next;
            }
            iter = iter->left;
        }
    }
};