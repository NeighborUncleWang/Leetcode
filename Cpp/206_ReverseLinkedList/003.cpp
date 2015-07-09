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
        auto newHead = reverseListHelper(head, head->next);
        head->next = nullptr;
        return newHead;
    }
    ListNode* reverseListHelper(ListNode* current, ListNode* next) {
        if (next == nullptr) {
            return current;
        }
        ListNode* newHead = reverseListHelper(current->next, next->next);
        next->next = current;
        return newHead;
    }
};
