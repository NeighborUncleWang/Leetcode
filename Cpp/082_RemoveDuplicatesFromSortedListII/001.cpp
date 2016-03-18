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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        auto predecessor = dummy;
        auto current = head;
        while (current) {
            int val = current->val;
            if (current->next && current->next->val == val) {
                while (current && current->val == val) {
                    predecessor->next = current->next;
                    delete current;
                    current = predecessor->next;
                }
            } else {
                predecessor = current;
                current = current->next;
            }
        }
        return dummy->next;
    }
};