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
        ListNode dummyNode(-1);
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        auto iter = dummy, pre = dummy;
        while (true) {
            for (int i = 0; i < k; ++i) {
                iter = iter->next;
                if (iter == nullptr) {
                    return dummy->next;
                }
            }
            auto next_pre = pre->next;
            for (int i = 0; i < k - 1; ++i) {
                //为了搞清这四个pointer操作
                //记住一点，当用temporary变量next记下iter->next之后
                //下一行一定是改变iter->next的值
                //这样可以防止出错
                auto next = iter->next;
                iter->next = pre->next;
                pre->next = pre->next->next;
                iter->next->next = next;
            }
            pre = next_pre;
            iter = pre;
        }
    }
};