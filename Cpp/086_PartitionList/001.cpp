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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* walker = sentinel;
        while (walker->next != nullptr && walker->next->val < x) {
            walker = walker->next;
        }
        ListNode* runner = walker->next;
        while (runner != nullptr && runner->next != nullptr) {
            if (runner->next->val < x) {
                auto temp = walker->next;
                auto temp2 = runner->next->next;
                walker->next = runner->next;
                walker->next->next = temp;
                runner->next = temp2;
                walker = walker->next;
            } else {
                runner = runner->next;
            }
        }
        auto result = sentinel->next;
        delete sentinel;
        return result;
    }
};
