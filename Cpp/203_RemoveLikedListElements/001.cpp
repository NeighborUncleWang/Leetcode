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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        auto iter = dummy;
        while (iter->next) {
            if (iter->next->val == val) {
                auto next = iter->next;
                iter->next = next->next;
                delete next;
            } else {
                iter = iter->next;
            }
        }
        return dummy->next;
    }
};