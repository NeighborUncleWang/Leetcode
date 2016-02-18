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
        ListNode* iter = head;
        int count = 0;
        while (iter != nullptr) {
            iter = iter->next;
            ++count;
        }
        return helper(head, 0, count - 1);
    }
private:
    TreeNode* helper(ListNode*& head, int start, int end) {
        if (end < start) {
            return nullptr;
        }
        int middle = start + (end - start) / 2;
        TreeNode* leftChild = helper(head, start, middle - 1);
        TreeNode* node = new TreeNode(head->val);
        node->left = leftChild;
        head = head->next;
        node->right = helper(head, middle + 1, end);
        return node;
    }
};