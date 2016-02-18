/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* predecessor = NULL;
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = predecessor;
            predecessor = current;
            current = next;
        }
        return predecessor;
    }
};
