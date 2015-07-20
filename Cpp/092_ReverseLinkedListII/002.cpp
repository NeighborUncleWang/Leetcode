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
        int i = 1;
        for ( ; predecessor->next != nullptr && i < m; ++i) {
            predecessor = predecessor->next;
        }
        if (i < m) {
            return head;
        }
        auto mNode = predecessor->next;
        auto current = mNode->next;
        for ( ; current != nullptr && i < n; ++i) {
            auto next = current->next;
            current->next = predecessor->next;
            predecessor->next = current;
            mNode->next = next;
            current = next;
        }
        auto result = dummy->next;
        delete dummy;
        return result;
    }
};
