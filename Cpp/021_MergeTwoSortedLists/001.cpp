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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        auto iter = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                iter->next = l1;
                l1 = l1->next;
            } else {
                iter->next = l2;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        iter->next = l1 ? l1 : l2;
        return dummy->next;
    }
};