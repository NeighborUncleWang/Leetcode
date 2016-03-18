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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        auto iter = dummy;
        while (iter->next && iter->next->next) {
            //first points to the 1st node in pair
            //second points to the 2nd node in pair
            auto first = iter->next;
            auto second = iter->next->next;
            iter->next = second;
            first->next = second->next;
            second->next = first;
            iter = first;
        }
        return dummy->next;
    }
};