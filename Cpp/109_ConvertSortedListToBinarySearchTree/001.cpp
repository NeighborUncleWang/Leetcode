/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* iterator = head;
        int length = 0;
        while (iterator != nullptr) {
            iterator = iterator->next;
            ++length;
        }
        return BSTHelper(head, length);
    }
    TreeNode *BSTHelper(ListNode*& head, int length) {
        if (length <= 0) {
            return nullptr;
        }
        TreeNode *parent, *leftChild, *rightChild;
        leftChild = BSTHelper(head, length / 2);
        parent = new TreeNode(head->val);
        head = head->next;
        rightChild = BSTHelper(head, length - length / 2 - 1);
        parent->left = leftChild;
        parent->right = rightChild;
        return parent;
    }
};
