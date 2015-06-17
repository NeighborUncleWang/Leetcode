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
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        auto temp = sentinel;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            if (temp->next->val == temp->next->next->val) {
                int val = temp->next->val;
                while (temp->next->val == val) {
                    auto p = temp->next;
                    temp->next = temp->next->next;
                    delete p;
                    if (temp->next == nullptr) {
                        break;
                    }
                }
            } else {
                temp = temp->next;
            }
        }
        auto p = sentinel-> next;
        delete sentinel;
        return p;
    }
};
