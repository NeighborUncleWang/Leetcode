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
        current->next = nullptr;//this is the magic code. This line changes the original head node's next to be nullptr. But actually it's not necessary to do it so many times, we can refer to 003.cpp to see another version of the codt necessary to do it so many times, we can refer to 003.cpp to see another version of the code.
        return newHead;
    }
};
