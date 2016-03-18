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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        auto predecessor = dummy;
        for (int i = 0; i < m - 1; ++i) {
            predecessor = predecessor->next;
        }
        auto start = predecessor->next;
        for (int i = 0; i < n - m; ++i) {
            auto then = start->next;
            start->next = then->next;
            then->next = predecessor->next;
            predecessor->next = then;
        }
        return dummy->next;
    }
};