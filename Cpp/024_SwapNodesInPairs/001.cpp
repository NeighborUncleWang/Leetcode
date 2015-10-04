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
    ListNode* swapPairs(ListNode* head) {
        ListNode temp(-1);
        auto dummy = &temp;
        dummy->next = head;
        auto previous = dummy;
        auto current = head;
        while (current && current->next) {
            auto next = current->next;
            current->next = next->next;
            next->next = current;
            previous->next = next;
            previous = current;
            current = current->next;
        }
        return dummy->next;
    }
};
