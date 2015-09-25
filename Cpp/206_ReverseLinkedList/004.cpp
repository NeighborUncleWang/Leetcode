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
        return helper(nullptr, head);
    }
private:
    ListNode* helper(ListNode* current, ListNode* next) {
        if (next == nullptr) {
            return current;
        }
        auto temp = next->next;
        next->next = current;
        return helper(next, temp);
    }
};
