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
    ListNode *detectCycle(ListNode *head) {
        ListNode* walker = head;
        ListNode* runner = head;
        while (runner != nullptr && runner->next != nullptr) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
                break;
        }
        if (runner == nullptr || runner->next == nullptr) {
            return nullptr;
        }
        walker = head;
        while (walker != runner) {
            walker = walker->next;
            runner = runner->next;
        }
        return walker;
    }
};
