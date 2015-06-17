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
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                auto p = temp->next;
                temp->next = temp->next->next;
                delete p;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
