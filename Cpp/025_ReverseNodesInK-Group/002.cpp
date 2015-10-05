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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }
        ListNode temp(-1);
        auto dummy = &temp;
        dummy->next = head;
        auto predecessor = dummy;
        auto current = dummy;
        int count = 0;
        while (current) {
            if (count == k) {
                predecessor = ReverseLikedList(predecessor, current->next);
                count = 0;
                current = predecessor;
            } else {
                current = current->next;
                ++count;
            }
        }
        return dummy->next;
    }
private:
    ListNode* ReverseLikedList(ListNode* dummy, ListNode* end) {
        auto head = dummy->next;
        auto predecessor = dummy->next;
        auto current = predecessor->next;
        while (current != end) {
            auto next = current->next;
            current->next = predecessor;
            predecessor = current;
            current = next;
        }
        head->next = current;
        dummy->next = predecessor;
        return head;
    }
};
