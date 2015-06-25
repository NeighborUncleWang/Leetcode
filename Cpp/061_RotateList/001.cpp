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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *runner = head, *walker = head;
        int i;
        for (i = 0; i < k && runner != nullptr; ++i) {
            runner = runner->next;
        }
        if (nullptr == runner) {
            k = k % i;
            runner = head;
            for (i = 0; i < k; ++i) {
                runner = runner->next;
            }
        }
        while (runner->next != nullptr) {
            runner = runner->next;
            walker = walker->next;
        }
        runner->next = head; //must be first connect the tail to the head, then connect walker->next to the NULL, otherwise when the List only has 1 node, it will cause some problems
        ListNode *next = walker->next; 
        walker->next = nullptr;
        return next;
    }
};
