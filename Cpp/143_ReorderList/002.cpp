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
        if (head == NULL) {
            return;
        }
        ListNode *walker = head, *runner = head;
        while (runner->next != NULL && runner->next->next != NULL) {
            walker = walker->next;
            runner = runner->next->next;
        }
        auto head1 = head;
        auto head2 = reverse(walker->next);
        walker->next = NULL;//here is the main difference between 001.cpp and 002.cpp
        while (head1 != NULL && head2 != NULL) {
            auto next2 = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = head2->next;
            head2 = next2;
        }
    }
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *current = head, *predecessor = NULL;
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = predecessor;
            predecessor = current;
            current = next;
        }
        return predecessor;
    }
};
