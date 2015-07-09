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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return reverseListHelper(head, head->next);
    }
    ListNode* reverseListHelper(ListNode* current, ListNode* next) {
        if (next == nullptr) {
            return current;
        }
        ListNode* newHead = reverseListHelper(current->next, next->next);
        next->next = current;
        current->next = nullptr;
        return newHead;
    }
};
