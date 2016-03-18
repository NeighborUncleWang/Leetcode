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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummyNode(0);
        //不要把dummy->next接到head上
        //否则题目会变更复杂
        //会需要一个额外变量指向iter之前的节点来保证每次iter被插入之后链表的连续性
        ListNode* dummy = &dummyNode;
        auto predecessor = dummy;
        auto iter = head;
        while (iter) {
            while (predecessor->next && predecessor->next->val < iter->val) {
                predecessor = predecessor->next;
            }
            auto next = iter->next;
            iter->next = predecessor->next;
            predecessor->next = iter;
            iter = next;
            predecessor = dummy;
        }
        return dummy->next;
    }
};