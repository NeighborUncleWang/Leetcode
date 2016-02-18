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
        return helper(nullptr, head);
    }
private:
    ListNode* helper(ListNode* previous, ListNode* current) {
        if (current == nullptr) {
            return previous;
        }
        auto next = current->next;
        current->next = previous;
        return helper(current, next);
    }
};