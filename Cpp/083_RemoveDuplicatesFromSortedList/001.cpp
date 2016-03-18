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
        auto iter = head;
        while (iter != nullptr && iter->next != nullptr) {
            if (iter->val == iter->next->val) {
                auto next = iter->next;
                iter->next = next->next;
                delete next;
            } else {
                iter = iter->next;
            }
        }
        return head;
    }
};