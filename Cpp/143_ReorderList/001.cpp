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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto start = slow->next;
        while (start->next) {
            auto then = start->next;
            start->next = then->next;
            then->next = slow->next;
            slow->next = then;
        }
        auto iter1 = head;
        auto iter2 = slow->next;
        slow->next = nullptr;
        while (iter2) {
            auto next = iter2->next;
            iter2->next = iter1->next;
            iter1->next = iter2;
            iter1 = iter2->next;
            iter2 = next;
        }
    }
};