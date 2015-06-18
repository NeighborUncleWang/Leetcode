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
    bool hasCycle(ListNode *head) {
        ListNode* runner = head;
        ListNode* walker = head;
        while (runner != nullptr && runner->next != nullptr) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) {
                return true;
            }
        }
        return false;
    }
};
