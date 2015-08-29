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
        auto dummy = ListNode(-1);
        int carry = 0;
        auto iterator = &dummy;
        for ( ; l1 || l2; 
        l1 = l1 == nullptr ? nullptr : l1->next,
        l2 = l2 == nullptr ? nullptr : l2->next, 
        iterator = iterator->next) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            int value = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            iterator->next = new ListNode(value);
        }
        if (carry) {
            iterator->next = new ListNode(1);
        }
        return dummy.next;
    }
};
