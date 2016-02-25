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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        auto p1 = &dummy1;
        auto p2 = &dummy2;
        auto current = head;
        while (current != nullptr) {
            //题目要求说
            //all nodes less than x come before nodes greater than or equal to x
            //所以这里只能用<不能用<=
            if (current->val < x) {
                p1->next = current;
                p1 = p1->next;
            } else {
                p2->next = current;
                p2 = p2->next;
            }
            current = current->next;
        }
        p2->next = nullptr;//important to add this to avoid cycle
        p1->next = dummy2.next;
        return dummy1.next;
    }
};