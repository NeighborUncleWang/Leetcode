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
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        auto iter = dummy;
        int carry = 0;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            iter->next = new ListNode(sum % 10);
            iter = iter->next;
            carry = sum / 10;
        }
        if (carry) {
            iter->next = new ListNode(1);
        }
        return dummy->next;
    }
};