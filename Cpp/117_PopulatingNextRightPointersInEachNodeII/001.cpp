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
        TreeLinkNode *currentLinkedListHead = nullptr;
        TreeLinkNode *previousLevelCurrent = root;
        TreeLinkNode *previousLevelHead = root;
        TreeLinkNode *predecessor = nullptr;
        while (previousLevelHead != nullptr) {//when previousLevelHead == nullptr, it means the whole tree is visited
            previousLevelCurrent = previousLevelHead;
            while (previousLevelCurrent != nullptr) {//when previousLevelCurrent == nullptr, it means this level is visited
                if (previousLevelCurrent->left) {
                    if (currentLinkedListHead == nullptr) {
                        currentLinkedListHead = previousLevelCurrent->left;
                        predecessor = currentLinkedListHead;
                    } else {
                        predecessor->next = previousLevelCurrent->left;
                        predecessor = predecessor->next;
                    }
                }
                if (previousLevelCurrent->right) {
                    if (currentLinkedListHead == nullptr) {
                        currentLinkedListHead = previousLevelCurrent->right;
                        predecessor = currentLinkedListHead;
                    } else {
                        predecessor->next = previousLevelCurrent->right;
                        predecessor = predecessor->next;
                    }
                }
                previousLevelCurrent = previousLevelCurrent->next;
            }
            previousLevelHead = currentLinkedListHead;
            currentLinkedListHead = nullptr;
        }
    }
};
