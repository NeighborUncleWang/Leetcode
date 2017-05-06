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
    ListNode* helper(ListNode* predecessor, ListNode* current) {
        if (current == nullptr) {
            return predecessor;
        }
        auto next = current->next;
        current->next = predecessor;
        return helper(current, next);
    }
};