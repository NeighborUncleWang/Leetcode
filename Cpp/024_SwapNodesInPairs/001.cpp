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
        ListNode* iterator = head;
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* predecessor = sentinel;
        while (iterator != nullptr && iterator->next != nullptr) {
            ListNode* successor = iterator->next;
            iterator->next = successor->next;
            successor->next = iterator;
            predecessor->next = successor;
            predecessor = iterator;
            iterator = iterator->next;
        }
        delete sentinel;
        return sentinel->next;
    }
};
