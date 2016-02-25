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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        dummy->next = head;
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* next = slow->next;
        slow->next = next->next;
        delete next;
        return dummy->next;
    }
};