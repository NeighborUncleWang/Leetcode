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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, value;
        ListNode* result = NULL;
        ListNode* tail = NULL;
        while (l1 != NULL && l2 != NULL) {
            value = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            ListNode* p = new ListNode(value);
            if (result == NULL) {
                result = p;    
            } else {
                tail->next = p;
            }
            tail = p;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            value = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            ListNode* p = new ListNode(value);
            if (result == NULL) {
                result = p;    
            } else {
                tail->next = p;
            }
            tail = p;
            l1 = l1->next;
        }
        while (l2) {
            value = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            ListNode* p = new ListNode(value);
            if (result == NULL) {
                result = p;    
            } else {
                tail->next = p;
            }
            tail = p;
            l2 = l2->next;
        }
        if (carry) {
            tail->next = new ListNode(1);
            tail = tail->next;
        }
        return result;
    }
};
