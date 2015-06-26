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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return sort(head);
    }
    ListNode* sort(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }
        ListNode *walker = head, *runner = head;
        while (runner->next != nullptr && runner->next->next != nullptr) {
            walker = walker->next;
            runner = runner->next->next;
        }
        auto next = walker->next;
        walker->next = nullptr;
        auto head1 = sort(head);
        auto head2 = sort(next);
        return merge(head1, head2);
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        auto helper = new ListNode(0);
        auto current = helper;
        auto iterator1 = head1;
        auto iterator2 = head2;
        while (iterator1 && iterator2) {
            if (iterator1->val < iterator2->val) {
                current->next = iterator1;
                iterator1 = iterator1->next;
            } else {
                current->next = iterator2;
                iterator2 = iterator2->next;
            }
            current = current->next;
        }
        if (iterator1) {
            current->next = iterator1;
        }
        if (iterator2) {
            current->next = iterator2;
        }
        auto result = helper->next;
        delete helper;
        return result;
    }
};
