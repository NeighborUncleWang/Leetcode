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
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto predecessor = dummy;
        for (int i = 1; i < m; ++i) {
            predecessor = predecessor->next;
        }
        auto mNode = predecessor->next;
        auto current = mNode->next;
        for (int i = m; i < n; ++i) {
            auto next = current->next;
            current->next = predecessor->next;
            predecessor->next = current;
            mNode->next = next;
            current = next;
        }
        return dummy->next;
    }
};
