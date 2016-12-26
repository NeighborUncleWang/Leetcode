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
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* i = dummy;
        ListNode* j = dummy;
        while (j != nullptr) {
            if (j->val != 9) i = j;
            j = j->next;
        }
        ++i->val;
        i = i->next;
        while (i != nullptr) {
            i->val = 0;
            i = i->next;
        }
        if (dummy->val == 1) {
            return dummy;
        } else {
            ListNode* result = dummy->next;
            delete dummy;
            return result;
        }
    }
};