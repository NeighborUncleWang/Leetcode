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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA, sizeB;
        ListNode *temp;
        temp = headA;
        for (sizeA = 0; temp != NULL; temp = temp->next) {
            ++sizeA;
        }
        temp = headB; 
        for (sizeB = 0; temp != NULL; temp = temp->next) {
            ++sizeB;
        }
        int difference = abs(sizeA - sizeB);
        auto p = sizeA > sizeB ? headA : headB;
        auto q = sizeA > sizeB ? headB : headA;
        while (difference > 0) {
            p = p->next;
            --difference;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
