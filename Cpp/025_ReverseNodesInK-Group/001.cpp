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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyNode(-1);
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        ListNode* iter = head;
        ListNode* predecessor = dummy;
        while (iter) {
            int count = 0;
            while (iter && count < k) {
                iter = iter->next;
                ++count;
            }
            if (count == k) {
                auto start = predecessor->next;
                for (int i = 0; i < k - 1; ++i) {
                    auto then = start->next;
                    start->next = then->next;
                    then->next = predecessor->next;
                    predecessor->next = then;
                }
                predecessor = start;
            }
        }
        return dummy->next;
    }
};